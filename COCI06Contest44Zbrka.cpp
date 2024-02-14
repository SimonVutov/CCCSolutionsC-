#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, c;
    cin >> n >> c;

    vector<vector<int> > dp(n + 1, vector<int>(c + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            if (j >= i)
                dp[i][j] = (dp[i][j] - dp[i - 1][j - i] + MOD) % MOD;
        }
    }

    cout << dp[n][c] << endl;
    return 0;
}
