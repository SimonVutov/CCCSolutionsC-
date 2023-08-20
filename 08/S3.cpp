#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int rows, cols;
        cin >> rows >> cols;
        int y = rows;
        int x = cols;

        int INF = 1000000;

        vector<vector<char> > a(rows, vector<char>(cols, ' '));
        vector<vector<int> > d(rows, vector<int>(cols, INF));
        for (int j = 0; j < rows; j++) {
            string line;
            cin >> line;
            for (int k = 0; k < cols; k++) {
                a[j][k] = line[k];
            }
        }

        d[0][0] = 1;
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));

        int move[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int cx = cur.first, cy = cur.second;

            for (int j = 0; j < 4; j++) {
                if (a[cy][cx] == '|' && j >= 2) continue;
                else if (a[cy][cx] == '-' && j < 2) continue;
                

                int nx = cx + move[j][0];
                int ny = cy + move[j][1];

                if (nx < 0 || nx > x-1 || ny < 0 || ny > y-1) continue;
                if (a[ny][nx] == '*') continue;
                if (d[ny][nx] != INF) continue;
                
                d[ny][nx] = d[cy][cx] + 1;
                
                q.push(make_pair(nx, ny));
            }
        }

        d[y-1][x-1] == INF ? cout << -1 << endl : cout << d[y-1][x-1] << endl;
    }
}