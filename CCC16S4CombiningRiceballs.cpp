#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

vector<int> sum (405, 0);

int su(int i, int j) {
    if (i == 0) return sum[j];
    return sum[j] - sum[i-1];
}

int main() {
    int N, result = 0;
    cin >> N;
    vector<vector<int> > dp(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        cin >> dp[i][i];
        sum[i] = (i > 0 ? sum[i - 1] + dp[i][i] : dp[i][i]);
        result = max(result, dp[i][i]);
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (i + 1 == j && dp[i][i] == dp[j][j]) {
                dp[i][j] = dp[i][i] + dp[j][j];
                result = max(result, dp[i][j]);
            }
            else {
                for (int l = i; l < j; l++) {
                    for (int r = l + 1; r <= j; r++) {
                        if (dp[i][l] != -1 && dp[l+1][r-1] != -1 && dp[r][j] != -1 && su(i, l)==su(r, j)) {
                            dp[i][j] = su(i, j);
                            result = max(result, dp[i][j]);
                        }
                    }
                    if (dp[i][l] != -1 && dp[l+1][j] != -1 && su(i, l)==su(l+1, j)) {
                        dp[i][j] = su(i, j);
                        result = max(result, dp[i][j]);
                    }
                }
            }
        }
    }

    cout << result << endl;
}