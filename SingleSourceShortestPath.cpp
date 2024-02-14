#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void calc(int at, unordered_map<int, unordered_map<int, int> >& adj, vector<int>& dist) {
    for (auto& neighbor : adj[at]) {
        int to = neighbor.first;
        int weight = neighbor.second;
        if (dist[to] > dist[at] + weight) {
            dist[to] = dist[at] + weight;
            calc(to, adj, dist);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, unordered_map<int, int> > adj;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (adj[a].find(b) == adj[a].end() || adj[a][b] > c) {
            adj[a][b] = c;
            adj[b][a] = c;
        }
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;
    calc(1, adj, dist);

    for (int i = 1; i <= n; i++) {
        cout << (dist[i] == INF ? -1 : dist[i]) << endl;
    }
}
