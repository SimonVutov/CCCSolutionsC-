#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<char> > grid (rows, vector<char> (cols));
    for (int i = 0; i < rows; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < cols; j++) grid[i][j] = s[j];
    }

    int step = 1;

    while (step < 1000) {

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 'S') continue;
                if (i > 0 && grid[i - 1][j] == '.') grid[i - 1][j] = 'H';
                if (i < rows - 1 && grid[i + 1][j] == '.') grid[i + 1][j] = 'H';
                if (j > 0 && grid[i][j - 1] == '.') grid[i][j - 1] = 'H';
                if (j < cols - 1 && grid[i][j + 1] == '.') grid[i][j + 1] = 'H';

                if (i > 0 && grid[i - 1][j] == 'D') {
                    cout << step << endl;
                    return 0;
                }
                if (i < rows - 1 && grid[i + 1][j] == 'D') {
                    cout << step << endl;
                    return 0;
                }
                if (j > 0 && grid[i][j - 1] == 'D') {
                    cout << step << endl;
                    return 0;
                }
                if (j < cols - 1 && grid[i][j + 1] == 'D') {
                    cout << step << endl;
                    return 0;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 'H') grid[i][j] = 'S';
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != '*') continue;
                if (i > 0 && (grid[i - 1][j] == '.' || grid[i - 1][j] == 'S')) grid[i - 1][j] = '0';
                if (i < rows - 1 && (grid[i + 1][j] == '.' || grid[i + 1][j] == 'S')) grid[i + 1][j] = '0';
                if (j > 0 && (grid[i][j - 1] == '.' || grid[i][j - 1] == 'S')) grid[i][j - 1] = '0';
                if (j < cols - 1 && (grid[i][j + 1] == '.' || grid[i][j + 1] == 'S')) grid[i][j + 1] = '0';
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == '0') grid[i][j] = '*';
        }
        step++;
    }

    cout << "KAKTUS" << endl;
}