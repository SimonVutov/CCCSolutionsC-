#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main () {
    int r = 0, c = 0;
    cin >> r >> c;
    vector <pair<int, int> > A[1001000]; //pair of (r, c)

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int p;
            cin >> p;
            A[p].push_back(make_pair(i + 1, j + 1));
        }
    }

    vector<int> q;
    bool visited[r + 1][c + 1];
    memset(visited, false, sizeof(visited));

    int cur = r * c;
    visited[r][c] = true;
    q.push_back(cur);

    while (!q.empty()) {
        int cur = q.back();
        q.pop_back();
        if (cur == 1) {
            cout << "yes" << endl;
            return 0;
        }
        for (int i = 0; i < (int)A[cur].size(); i++) {
            int row = A[cur][i].first;
            int col = A[cur][i].second;
            if (!visited[row][col]) {
                visited[row][col] = true;
                q.push_back(row * col);
            }
        }
    }

    cout << "no" << endl;
    return 0;
}