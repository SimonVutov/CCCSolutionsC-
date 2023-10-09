#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;

int maxPath(int row, int col, vector<vector<int> > &triangle, int sum = 0) {
    if (row == (int)triangle.size() - 1) return sum + triangle[row][col];
    return max(maxPath(row + 1, col, triangle, sum + triangle[row][col]), maxPath(row + 1, col + 1, triangle, sum + triangle[row][col]));
}

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
