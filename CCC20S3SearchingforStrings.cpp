#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

long long hsh[200010], pw[200010], base = 131;
int fs[26], ft[26];
unordered_set<long long> st;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 1; i <= n; i++) fs[s[i-1]-'a']++;

    pw[0] = 1;
    for (int i = 1; i <= m; i++){
        hsh[i] = hsh[i-1] * base + t[i-1];
        pw[i] = pw[i-1] * base;
    }

    for (int i = 1; i <= m; i++){
        ft[t[i-1]-'a']++;
        if (i < n) continue;
        if (i > n) ft[t[i-n-1]-'a']--;
        for (int i = 0; i < 26; i++)
            if (fs[i] != ft[i]) goto skipped;
        st.insert(hsh[i] - hsh[i-n]*pw[n]);
        skipped:
    }
    cout << st.size() << endl;
}