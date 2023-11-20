#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;

int main () {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> v (n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<int> > visitFirst (n, vector<int> ());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        visitFirst[a-1].push_back(b-1);
    }

    int furthest = 0;
    int at = p - 1;
    while (true) {
        int reached = 0;
        int nDown, nUp;

        //go down as far

        while(true) {
            for (int i = 0; i < (int)visitFirst.size(); i++) {
                for (int j = 0; j < (int)visitFirst[i].size(); j++) {
                    if (visitFirst[i][j] == at) {
                        visitFirst[i].erase(visitFirst[i].begin() + j);
                        break;
                    }
                }
            }

            int next = -1;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i == at) continue;
                if (v[i] < v[at] && (int)visitFirst[i].size() == 0) {
                    if (next == -1) {
                        next = i;
                    } else if (v[i] > v[next]) {
                        next = i;
                    }
                }
            }

            if (next == -1) {
                nDown = 1e9;
                reached++;
                break;
            }

            if (v[at] - v[next] > furthest) {
                nDown = v[at] - v[next];
                break;
            }
            
            at = next;
            //cout << "tried down: " << at << endl;
        }

        //go up as far

        while(true) {
            for (int i = 0; i < (int)visitFirst.size(); i++) {
                for (int j = 0; j < (int)visitFirst[i].size(); j++) {
                    if (visitFirst[i][j] == at) {
                        visitFirst[i].erase(visitFirst[i].begin() + j);
                        break;
                    }
                }
            }

            int next = -1;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i == at) continue;
                if (v[i] > v[at] && (int)visitFirst[i].size() == 0) {
                    if (next == -1) {
                        next = i;
                    } else if (v[i] < v[next]) {
                        next = i;
                    }
                }
            }

            if (next == -1) {
                nUp = 1e9;
                reached++;
                break;
            }

            if (v[next] - v[at] > furthest) {
                nUp = v[next] - v[at];
                break;
            }
            
            at = next;
            //cout << "tried uo: " << at << endl;
        }

        //go down as far

        while(true) {
            for (int i = 0; i < (int)visitFirst.size(); i++) {
                for (int j = 0; j < (int)visitFirst[i].size(); j++) {
                    if (visitFirst[i][j] == at) {
                        visitFirst[i].erase(visitFirst[i].begin() + j);
                        break;
                    }
                }
            }

            int next = -1;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i == at) continue;
                if (v[i] < v[at] && (int)visitFirst[i].size() == 0) {
                    if (next == -1) {
                        next = i;
                    } else if (v[i] > v[next]) {
                        next = i;
                    }
                }
            }

            if (next == -1) {
                nDown = 1e9;
                reached++;
                break;
            }

            if (v[at] - v[next] > furthest) {
                nDown = v[at] - v[next];
                break;
            }
            
            at = next;
            //cout << "tried down: " << at << endl;
        }

        //go up as far

        while(true) {
            for (int i = 0; i < (int)visitFirst.size(); i++) {
                for (int j = 0; j < (int)visitFirst[i].size(); j++) {
                    if (visitFirst[i][j] == at) {
                        visitFirst[i].erase(visitFirst[i].begin() + j);
                        break;
                    }
                }
            }

            int next = -1;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i == at) continue;
                if (v[i] > v[at] && (int)visitFirst[i].size() == 0) {
                    if (next == -1) {
                        next = i;
                    } else if (v[i] < v[next]) {
                        next = i;
                    }
                }
            }

            if (next == -1) {
                nUp = 1e9;
                reached++;
                break;
            }

            if (v[next] - v[at] > furthest) {
                nUp = v[next] - v[at];
                break;
            }
            
            at = next;
            //cout << "tried uo: " << at << endl;
        }

        //go down as far

        while(true) {
            for (int i = 0; i < (int)visitFirst.size(); i++) {
                for (int j = 0; j < (int)visitFirst[i].size(); j++) {
                    if (visitFirst[i][j] == at) {
                        visitFirst[i].erase(visitFirst[i].begin() + j);
                        break;
                    }
                }
            }

            int next = -1;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i == at) continue;
                if (v[i] < v[at] && (int)visitFirst[i].size() == 0) {
                    if (next == -1) {
                        next = i;
                    } else if (v[i] > v[next]) {
                        next = i;
                    }
                }
            }

            if (next == -1) {
                nDown = 1e9;
                reached++;
                break;
            }

            if (v[at] - v[next] > furthest) {
                nDown = v[at] - v[next];
                break;
            }
            
            at = next;
            //cout << "tried down: " << at << endl;
        }

        //go up as far

        while(true) {
            for (int i = 0; i < (int)visitFirst.size(); i++) {
                for (int j = 0; j < (int)visitFirst[i].size(); j++) {
                    if (visitFirst[i][j] == at) {
                        visitFirst[i].erase(visitFirst[i].begin() + j);
                        break;
                    }
                }
            }

            int next = -1;
            for (int i = 0; i < (int)v.size(); i++) {
                if (i == at) continue;
                if (v[i] > v[at] && (int)visitFirst[i].size() == 0) {
                    if (next == -1) {
                        next = i;
                    } else if (v[i] < v[next]) {
                        next = i;
                    }
                }
            }

            if (next == -1) {
                nUp = 1e9;
                reached++;
                break;
            }

            if (v[next] - v[at] > furthest) {
                nUp = v[next] - v[at];
                break;
            }
            
            at = next;
            //cout << "tried uo: " << at << endl;
        }

        if (reached == 6) break;
        furthest = max(furthest, min(nDown, nUp));
    }

    cout << furthest << endl;
}