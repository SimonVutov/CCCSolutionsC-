#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n + 1);
    vector<vector<int> > adj2(m + 1);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj2[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        queue<int> q; //negetive will mean left group
        q.push(-i);
        vector<bool> vis(n + 1);
        vector<bool> vis2(m + 1);
        vis[i] = true;
        int steps = 1;

        while (!q.empty()) {

            if (steps > 5) break;
            int cur = q.front();
            q.pop();
            
            if (steps == 2) vis[i] = false;
            if (steps > 2 && -cur == i) {
                cout << "NO" << endl;
                return 0;
            }

            if (cur < 0) {
                cur = -cur;
                for (int j = 0; j < adj[cur].size(); j++) {
                    if (!vis[adj[cur][j]]) {
                        vis[adj[cur][j]] = true;
                        q.push(-adj[cur][j]);
                    }
                }
            } else {
                for (int j = 0; j < adj2[cur].size(); j++) {
                    if (!vis2[adj2[cur][j]]) {
                        vis2[adj2[cur][j]] = true;
                        q.push(adj2[cur][j]);
                    }
                }
            }

            steps++;
        }
    }

    cout << "YES" << endl;
    return 0;
}
/*
5 4
5
1 1
2 2
1 2
2 1
4 4

*/