#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    int max_v = 0;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
        max_v += v[i];
    }

    vector<int> dp(max_v+1, 0);
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        vector<int> next_dp(W+1, 0);
        for (int j = W; j >= 0; j--) {
            if (j - w[i] >= 0) {
                next_dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            } else {
                next_dp[j] = dp[j];
            }
        }
        dp = next_dp;
    }

    cout << dp[W] << endl;

    return 0;
}
