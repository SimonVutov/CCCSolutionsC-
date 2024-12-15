#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    vector<vector<int> > v(row, vector<int>(col, -1));
    int maxV = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int val = 1;
            for (int k = 0; k < 9; k++) {
                if (i > 0) {
                    if (val == v[i - 1][j]) {
                        val++;
                    }
                }
                if (i < row - 1) {
                    if (val == v[i + 1][j]) {
                        val++;
                    }
                }
                if (j < col - 1) {
                    if (val == v[i][j + 1]) {
                        val++;
                    }
                }
                if (j > 0) {
                    if (val == v[i][j - 1]) {
                        val++;
                    }
                }
                if (i < row - 1 && j < col - 1) {
                    if (val == v[i + 1][j + 1]) {
                        val++;
                    }
                }
                if (i > 0 && j > 0) {
                    if (val == v[i - 1][j - 1]) {
                        val++;
                    }
                }
                if (i < row - 1 && j > 0) {
                    if (val == v[i + 1][j - 1]) {
                        val++;
                    }
                }
                if (i > 0 && j < col - 1) {
                    if (val == v[i - 1][j + 1]) {
                        val++;
                    }
                }
            }
            v[i][j] = val;
            maxV = max(maxV, val);
        }
    }
    cout << maxV << endl;
    //cout v
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}