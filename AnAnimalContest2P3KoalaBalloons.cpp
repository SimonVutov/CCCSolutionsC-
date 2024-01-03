#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int> > v (rows, vector<int> (cols, 0)), maxSize(rows, vector<int> (cols, -1));
    for (int i = 0; i < rows; i++) {
        string s; cin >> s;
        for (int j = 0; j < cols; j++) {
            if (s[j] == 'X') v[i][j] = 1;
        }
    }

    for (int i = 0; i < rows; i++) maxSize[i][cols-1] = (v[i][cols-1] == 0 ? 1 : 0);
    for (int i = 0; i < cols; i++) maxSize[rows-1][i] = (v[rows-1][i] == 0 ? 1 : 0);
    for (int i = rows - 2; i >= 0; i--) {
        for (int j = cols - 2; j >= 0; j--) {
            if (v[i][j] == 1) maxSize[i][j] = 0;
            else maxSize[i][j] = min(maxSize[i+1][j], min(maxSize[i][j+1], maxSize[i+1][j+1])) + 1;
        }
    }

    vector<vector<int> > vis (rows, vector<int> (cols, 0));
    priority_queue<pair<int, pair<int, int> > > pq; //maxSize, row, col
    pq.push(make_pair(maxSize[0][0], make_pair(0, 0)));

    while (!pq.empty()) {
        if (pq.empty()) {
            cout << 0 << endl;
            return 0;
        }
        int curMax = pq.top().first, curRow = pq.top().second.first, curCol = pq.top().second.second;
        pq.pop();
        int newMax = min(curMax, maxSize[curRow][curCol]);

        if (curRow + curMax == rows && curCol + curMax == cols) {
            cout << newMax << endl;
            return 0;
        }

        if (curRow + newMax >= rows || curCol + newMax >= cols || curCol < 0 || curRow < 0) {
            continue;
        }

        if (vis[curRow][curCol] == 1) continue;
        vis[curRow][curCol] = 1;

        //pq.push(make_pair(newMax, make_pair(curRow + 1, curCol)));
        //pq.push(make_pair(newMax, make_pair(curRow, curCol + 1)));
        //pq.push(make_pair(newMax, make_pair(curRow - 1, curCol)));
        //pq.push(make_pair(newMax, make_pair(curRow, curCol - 1)));
        if (curRow > 0) pq.push(make_pair(newMax, make_pair(curRow - 1, curCol)));
        if (curCol > 0) pq.push(make_pair(newMax, make_pair(curRow, curCol - 1)));
        if (curRow + newMax < rows) pq.push(make_pair(newMax, make_pair(curRow + 1, curCol)));
        if (curCol + newMax < cols) pq.push(make_pair(newMax, make_pair(curRow, curCol + 1)));
    }

    cout << 0 << endl;
}