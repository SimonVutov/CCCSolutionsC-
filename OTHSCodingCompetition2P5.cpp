#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void dfs(vector<vector<char> > &grid, vector<vector<int> > &vis, int i, int j, int row, int col, bool &hitPerson) {
    if (i < 0 || i >= row || j < 0 || j >= col || vis[i][j] == 1 ||  grid[i][j] == 'X') return;
    vis[i][j] = 1;
    if (grid[i][j] == '*') hitPerson = true;
    dfs(grid, vis, i + 1, j, row, col, hitPerson);
    dfs(grid, vis, i - 1, j, row, col, hitPerson);
    dfs(grid, vis, i, j + 1, row, col, hitPerson);
    dfs(grid, vis, i, j - 1, row, col, hitPerson);
}

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<char> > grid (row, vector<char>(col, 0));
    vector<vector<int> > vis (row, vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }

    int empty = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (vis[i][j] == 1 || grid[i][j] == 'X') continue;
            bool hitPerson = false;
            dfs(grid, vis, i, j, row, col, hitPerson);
            if (!hitPerson) empty++;
        }
    }
    cout << empty;
}