#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<char> > grid(row, vector<char>(col));
    for (int i = 0; i < row; i++) for (int j = 0; j < col; j++) cin >> grid[i][j];
    vector<vector<int> > dp(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        if (grid[i][0] == '#') break;
        dp[i][0] = 1;
    }
    for (int i = 0; i < col; i++) {
        if (grid[0][i] == '#') break;
        dp[0][i] = 1;
    }

    for (int i = 1; i < row; i++) for (int j = 1; j < col; j++) {
        if (grid[i][j] == '#') continue;
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
    }

    cout << dp[row - 1][col - 1] << endl;

    return 0;
}
