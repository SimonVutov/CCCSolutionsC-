#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
using namespace std;

int main () {
    vector<vector<int> > adj (26, vector<int>());
    string s;
    int t = 0;
    while (true) {
        cin >> s;
        if (s == "**") break;
        adj[s[0] - 'A'].push_back(s[1] - 'A');
        adj[s[1] - 'A'].push_back(s[0] - 'A');
    }

    for (int i = 0; i < (int)adj.size(); i++) {
        for (int j = 0; j < (int)adj[i].size(); j++) {
            queue<int> q;
            q.push(0); // push 0, looking for 1
            vector<int> vis (26, -1);
            vis[0] = 1;

            bool found = false;

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (cur == 1) { found = true; break; }

                for (int k = 0; k < (int)adj[cur].size(); k++) {
                    if (cur == i && k == j) continue; // if this edge is disabled, skip
                    if (vis[adj[cur][k]] == 1) continue; // if visited
                    q.push(adj[cur][k]);
                    vis[adj[cur][k]] = 1;
                }
            }

            if (!found) {
                cout << static_cast<char>('A' + i) << static_cast<char>('A' + adj[i][j]) << endl;
                t++;
            }
        }
    }
    cout << "There are " << t << " disconnecting roads." << endl;
}