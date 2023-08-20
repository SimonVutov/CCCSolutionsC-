#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <utility>

using namespace std;

int main () {
    int y=0, x=0;
    cin >> y >> x;

    vector<vector<char> > a (y, vector<char>(x));
    vector<vector<int> > d (y, vector<int>(x, -1));
    // Loop to fill each row of the 'd' vector with a value of 1000000
    int inf = 1000000;
    for (int i = 0; i < y; i++) {
        fill(d[i].begin(), d[i].end(), inf);
    }

    int sx=0, sy=0;
    
    for (int i = 0; i < y; i++) {
        string s = "";
        cin >> s;
        for (int j = 0; j < x; j++) {
            a[i][j] = s[j];
            if (s[j] == 'S') {
                sx = j;
                sy = i;
            }
        }
    }

    int move[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    int cam[y][x];
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cam[i][j] = 0;
        }
    }
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (a[i][j] == 'C') {
                cam[i][j] = 1;
                for (int k = 0; k < 4; k++) {
                    int nx = j + move[k][0];
                    int ny = i + move[k][1];
                    while (a[ny][nx] != 'W') {
                        cam[ny][nx] = 1;
                        nx += move[k][0];
                        ny += move[k][1];
    }   }   }   }   }

    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    d[sy][sx] = 0;

    while (!q.empty()) {
        pair<int, int> c = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = c.first + move[i][0];
            int ny = c.second + move[i][1];

            bool stuck = false;
            if (a[ny][nx] == 'U' || a[ny][nx] == 'R' || a[ny][nx] == 'D' || a[ny][nx] == 'L') {
                int counter = 0;
                while (a[ny][nx] != 'W' && a[ny][nx] != '.') {
                    counter++;
                    if (counter > 1000) { stuck = true; break; }
                    if (a[ny][nx] == 'U') ny--;
                    else if (a[ny][nx] == 'R') nx++;
                    else if (a[ny][nx] == 'D') ny++;
                    else if (a[ny][nx] == 'L') nx--;
                }
            }

            if (stuck) continue; //stuck in loop
            if (ny < 0 || ny >= y || nx < 0 || nx >= x) continue; //bounds
            if (d[ny][nx] != inf) continue; //visited
            if (a[ny][nx] == 'W') continue; //wall
            if (cam[ny][nx] == 1) continue; //camera
            
            d[ny][nx] = min(d[ny][nx], d[c.second][c.first] + 1);
            q.push(make_pair(nx, ny));
        }
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (a[i][j] == '.') {
                if (cam[sy][sx] == 1) cout << "-1\n"; //spawned beside camera, means you can't move
                else d[i][j] == inf ? cout << "-1\n" : cout << d[i][j] << "\n";
            }
        }
    }
}