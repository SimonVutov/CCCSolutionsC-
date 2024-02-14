#include <iostream>
#include <unordered_set>
#include <string>
#include <functional>

using namespace std;

void makeS(string &s, string current, int index, unordered_set<size_t> &subsequences) {
    if (index == (int)s.length()) {
        hash<string> hasher;
        subsequences.insert(hasher(current));
        return;
    }
    makeS(s, current + s[index], index + 1, subsequences);
    makeS(s, current, index + 1, subsequences);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;

    unordered_set<size_t> subsequences;
    makeS(s, "", 0, subsequences);
    int ans = subsequences.size();
    cout << ans - 1 << endl;
    return 0;
}
