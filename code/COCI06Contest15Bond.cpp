#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<double> > dp;

double calculateMaxProduct(const vector<vector<int> >& board, vector<int>& used) {
    int n = board.size();
    
    // dp[i][mask] stores the maximum product when considering the first i columns
    // and using the numbers indicated by the bitmask 'mask'
    dp.assign(n + 1, vector<double>(1 << n, -1.0));

    // Base case: no columns considered yet
    dp[0][0] = 1.0;

    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int j = 0; j < n; ++j) {
                if ((mask & (1 << j)) == 0 && !used[j]) {
                    double product = dp[i - 1][mask] * board[j][i - 1] / 100.0;
                    dp[i][mask | (1 << j)] = max(dp[i][mask | (1 << j)], product);
                }
            }
        }
    }

    // Find the maximum product considering all columns
    double result = 0.0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        result = max(result, dp[n][mask]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> used(n, 0);
    vector<vector<int> > board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << fixed << setprecision(7) << calculateMaxProduct(board, used) * 100 << endl;

    return 0;
}
