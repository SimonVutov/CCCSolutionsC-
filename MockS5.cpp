#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    

    cin >> n;
    vector<int> t (n), d (n);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    vector<vector<int> > dp (n, vector<int> (2, INT_MAX));

    dp[0][0] = t[0];
    dp[0][1] = t[0];

    dp[1][0] = dp[0][0] + t[0] + t[1];
    dp[1][1] = min(dp[1][0], t[0] + d[0] + t[1]);

    for (int i = 2; i < n; i++) {
        dp[i][0] = dp[i-1][0] + (dp[i-2][0] - dp[i-1][0]) + t[i];
        dp[i][1] = min(dp[i][0], dp[i-1][1] + t[i] + d[i-1]);
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << endl;
}