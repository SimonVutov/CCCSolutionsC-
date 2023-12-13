#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    vector<vector<char> > grid (y, vector<char> (x, ' '));
    for (int i = 0; i < y; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < x; j++) {
            grid[i][j] = s[j];
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    vector<vector<int> > dist (y, vector<int> (x, -1));
    dist[0][0] = 0;
    while (!q.empty()) {
        int xCur = q.front().first;
        int yCur = q.front().second;
        q.pop();
        if (xCur == x-1 && yCur == y-1) break;

        if (xCur > 0 && grid[yCur][xCur-1] != '#' && dist[yCur][xCur-1] == -1) {
            dist[yCur][xCur-1] = dist[yCur][xCur] + 1;
            q.push(make_pair(xCur-1, yCur));
        }

        if (xCur < x-1 && grid[yCur][xCur+1] != '#' && dist[yCur][xCur+1] == -1) {
            dist[yCur][xCur+1] = dist[yCur][xCur] + 1;
            q.push(make_pair(xCur+1, yCur));
        }

        if (yCur > 0 && grid[yCur-1][xCur] != '#' && dist[yCur-1][xCur] == -1) {
            dist[yCur-1][xCur] = dist[yCur][xCur] + 1;
            q.push(make_pair(xCur, yCur-1));
        }

        if (yCur < y-1 && grid[yCur+1][xCur] != '#' && dist[yCur+1][xCur] == -1) {
            dist[yCur+1][xCur] = dist[yCur][xCur] + 1;
            q.push(make_pair(xCur, yCur+1));
        }
    }

    cout << dist[y-1][x-1] << endl;
}
