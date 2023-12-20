#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int calc(vector<vector<vector<int> > > &dp, vector<vector<int> > &grid, int y, int x, int points = 0, int dir = 0) {
    if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return -5000000;
    if (x == grid[0].size() - 1 && y == grid.size() - 1) return points;
    if (grid[y][x] < -1000000) return -5000000;
    if (dp[y][x][dir] != -1) return dp[y][x][dir];

    int maxP = -5000000;
    int nP = points + grid[y][x];
    cout << " at y of " << y << " and x of " << x << " and points of " << nP << endl;

    cout << "    going to go more in that direction " << dir << endl;
    if (dir == 1) maxP = max(maxP, calc(dp, grid, y + 1, x, nP, 1)); //up
    else if (dir == 0) maxP = max(maxP, calc(dp, grid, y - 1, x, nP, 0)); //down
    
    
    cout << "    going to go right and up" << endl;
    maxP = calc(dp, grid, y, x + 1, nP, 1);
    cout << "    going to go right and down" << endl;
    maxP = max(maxP, calc(dp, grid, y, x + 1, nP, 0));

    

    dp[y][x][dir] = maxP;
    return maxP;
}

int main() {
    int y, x;
    while (true) {
        cin >> y >> x;
        if (y == 0 && x == 0) break;

        vector<vector<int> > grid (y, vector<int>(x));
        vector<vector<vector<int> > > dp (y, vector<vector<int> >(x, vector<int>(2, -1)));

        for (int i = 0; i < y; i++) {
            string line;
            cin >> line;
            for (int j = 0; j < x; j++) {
                if (line[j] - '0' >= 0 && line[j] - '0' <= 9) {
                    grid[i][j] = line[j] - '0';
                } else if (line[j] == '*') {
                    grid[i][j] = -5000000;
                } else if (line[j] == '.') {
                    grid[i][j] = 0;
                }
            }
        }

        int maxPoints = calc(dp, grid, grid.size() - 1, 0) + grid[grid.size() - 1][grid[0].size() - 1];

        cout << maxPoints << endl;
    }
}
