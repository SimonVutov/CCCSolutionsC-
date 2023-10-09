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

    int n, k;
    cin >> n >> k;
    vector<vector<pair<int, int> > > adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }

    int minCities = 1000000000;

    for (int i = 0; i < n; i++) {
        vector<int> dist(n + 1, 1000000000);
        vector<int> city(n + 1, 0);
        queue<int> q;
        q.push(i);
        dist[i] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (dist[cur] == k) minCities = min(minCities, city[cur]);
            if (dist[cur] > k) continue;

            for (int j = 0; j < (int)adj[cur].size(); j++) {
                if (dist[cur] + adj[cur][j].second < dist[adj[cur][j].first]) {
                    dist[adj[cur][j].first] = dist[cur] + adj[cur][j].second;
                    city[adj[cur][j].first] = city[cur] + 1;
                    q.push(adj[cur][j].first);
                }
            }
        }
    }

    cout << (minCities == 1000000000 ? -1 : minCities) << endl;
}