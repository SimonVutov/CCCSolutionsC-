#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > wv (n);
    for (int i = 0; i < n; i++) cin >> wv[i].first >> wv[i].second;
    vector<vector<long long> > dp (n + 1, vector<long long> (k + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j >= wv[i].first) dp[i + 1][j] = max(dp[i][j], dp[i][j - wv[i].first] + wv[i].second);
            else dp[i + 1][j] = dp[i][j];
        }
    }
    cout << dp[n][k] << endl;
}
