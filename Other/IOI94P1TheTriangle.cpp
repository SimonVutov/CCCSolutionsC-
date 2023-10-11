#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > dp(100, vector<int>(100, -1));

int maxPath(int row, int col, vector<vector<int> >& triangle) {
    if (dp[row][col] != -1) return dp[row][col];
    if (row == (int)triangle.size() - 1) return dp[row][col] = triangle[row][col];
    return dp[row][col] = triangle[row][col] + max(maxPath(row + 1, col, triangle), maxPath(row + 1, col + 1, triangle));
} //this position + the max of left and right paths

int main() {
    int levels;
    cin >> levels;
    vector<vector<int> > triangle(levels, vector<int>(levels));
    for (int i = 0; i < levels; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    cout << maxPath(0, 0, triangle) << endl;
}
