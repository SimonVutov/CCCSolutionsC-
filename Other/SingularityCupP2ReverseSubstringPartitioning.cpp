#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;

int main () {
    int n;
    string s;
    cin >> n >> s;
    if (s[0] != s[n - 1]) {
        cout << n;
        return 0;
    }
    int t = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            t++;
        }
    }
    cout << n - t;
}
/*
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>

using namespace std;

unordered_map<string, int> memo;

int minSplit(string s) {
    int n = s.length();
    if (n == 1) return 1;
    if (n == 0) return 0;
    if (s[0] != s[n-1]) return n;
    if (memo.find(s) != memo.end()) return memo[s];

    int minReturn = n - 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) continue;
        string s1 = s.substr(1, i);
        string s2 = s.substr(i+1, n-1);
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        minReturn = min(minReturn, minSplit(s1 + s2));
    }

    memo[s] = minReturn;
    return minReturn;
}

int main () {
    int n;
    string s;
    cin >> n >> s;
    cout << minSplit(s);
}*/