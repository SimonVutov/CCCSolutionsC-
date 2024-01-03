#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t = 0; cin >> n;
    string s; cin >> s;
    vector<int> v (26, 0);
    for (int i = 0; i < n; i++) v[s[i]-'a']++;
    for (int i = 0; i < 26; i++) t += v[i] % 2;
    cout << max(t, 1) << endl;
}