#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M;

void trim(int root, vector<vector<int> >& adj, vector<int>& pho) {
    for (int i = 0; i < (int)pho.size(); i++) if (pho[i] == root) return;
    if (adj[root].size() == 1) {
        for (int i = 0; i < (int)adj[root].size(); i++) {
            for (int j = 0; j < (int)adj[adj[root][i]].size(); j++) {
                if (adj[adj[root][i]][j] == root) {
                    adj[adj[root][i]].erase(adj[adj[root][i]].begin() + j);
                    trim(adj[root][i], adj, pho);
                    break;
                }
            }
        }
        adj[root].clear();
    }
}

int main() {
    cin >> N >> M;
    vector<int> pho(M);
    for (int i = 0; i < M; i++) cin >> pho[i];
    vector<vector<int> > adj(N, vector<int>());
    int root = 1e9;
    for (int i = 0; i < M; i++) root = min(root, pho[i]);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N; i++) trim(i, adj, pho);

    int diameter = 0;
    int totalEdges = -1; // -1 because nodes-1 = edges

    //bfs to furthest point, counting totalEdges;
    queue<int> q;
    vector<int> visited(N, 0);
    q.push(root);
    visited[root] = 1;
    int lastPoint = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        totalEdges++;
        lastPoint = cur;
        for (int i = 0; i < (int)adj[cur].size(); i++) {
            if (visited[adj[cur][i]]) continue;
            visited[adj[cur][i]] = 1;
            q.push(adj[cur][i]);
        }
    }

    //bfs from furthest point to furthest point, counting diameter;
    vector<int> distance(N, -1);
    q.push(lastPoint);
    distance[lastPoint] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < (int)adj[cur].size(); i++) {
            if (distance[adj[cur][i]] != -1) continue;
            distance[adj[cur][i]] = distance[cur] + 1;
            q.push(adj[cur][i]);
        }
    }

    for (int i = 0; i < (int)distance.size(); i++) diameter = max(diameter, distance[i]);
    cout << (diameter + 2 * (totalEdges - diameter)) << endl;
}