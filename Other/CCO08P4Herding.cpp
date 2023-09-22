#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = s[j];
        }
    }

    char from[4] = {'N', 'S', 'W', 'E'};
    int to[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    //at each points that is still -1
        // travel down its path
            //if reach a already set node, make all the nodes in the path the same value
            //if reached a already visited node, or reach a wall, make all the nodes in the path a new value

    vector<vector<int> > v(n, vector<int>(m, -1));
    int counter = 5;
    queue<pair<int, int> > q;
    stack<pair<int, int> > curVisited;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (v[i][j] != -1) continue;
            q.push(make_pair(i, j));
            curVisited.push(make_pair(i, j));

            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    if (grid[cur.first][cur.second] == from[k]) {
                        int newC = cur.first + to[k][0];
                        int newR = cur.second + to[k][1];

                        if (newC < 0 || newC >= n || newR < 0 || newR >= m) {
                            while (!curVisited.empty()) {
                                pair<int, int> cur = curVisited.top();
                                curVisited.pop();
                                v[cur.first][cur.second] = counter;
                            }
                            counter++;
                            break;
                        } else {
                            if (v[newC][newR] == -2) {
                                while (!curVisited.empty()) {
                                    pair<int, int> cur = curVisited.top();
                                    curVisited.pop();
                                    v[cur.first][cur.second] = counter;
                                }
                                counter++;
                                break;
                            } else if (v[newC][newR] != -1) {
                                while (!curVisited.empty()) {
                                    pair<int, int> cur = curVisited.top();
                                    curVisited.pop();
                                    v[cur.first][cur.second] = v[newC][newR];
                                }
                                break;
                            } else {
                                q.push(make_pair(newC, newR));
                                curVisited.push(make_pair(newC, newR));
                                v[newC][newR] = -2;
                            }
                        }
                    }
                }
            }
        }
    }

    set<int> s;
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v[i].size(); j++) {
            s.insert(v[i][j]);
        }
    }

    cout << s.size() << endl;
}
