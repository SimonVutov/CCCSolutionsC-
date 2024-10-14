#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

int lcm (string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<int> dp (m + 1, 0);
    for (int i = 1; i <= n; i++) {
        vector<int> newdp (m + 1, 0);
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                newdp[j] = dp[j - 1] + 1;
            } else {
                newdp[j] = max(dp[j], newdp[j - 1]);
            }
        }
        dp = newdp;
    }
    return dp[m];
}

int main() {
    int n;
    cin >> n;
    string s, Sreverse;
    cin >> s;
    Sreverse = s;
    reverse(Sreverse.begin(), Sreverse.end());
    cout << n - lcm(s, Sreverse) << endl;
}
