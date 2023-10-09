#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > v (n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    int diameter;

    queue<int> q;
    vector<int> dist (n + 1, 1000000000);
    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < (int)v[cur].size(); i++) {
            int next = v[cur][i].first;
            if (next >= 0 && next < n && dist[next] > dist[cur] + v[cur][i].second) {
                dist[next] = dist[cur] + v[cur][i].second;
                q.push(next);
            }
        }
    }

    int maxDist = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
            maxIndex = i;
        }
    }

    q.push(maxIndex);
    dist = vector<int> (n, 1000000000);
    dist[maxIndex] = 0;

    vector<int> path (n, -1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < (int)v[cur].size(); i++) {
            int next = v[cur][i].first;
            if (next >= 0 && next < n && dist[next] > dist[cur] + v[cur][i].second) {
                dist[next] = dist[cur] + v[cur][i].second;
                q.push(next);
                path[next] = cur + 1;
            }
        }
    }

    maxDist = 0;
    maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (dist[i] > maxDist) {
            maxDist = dist[i];
            maxIndex = i;
        }
    }

    diameter = maxDist;

    int at = maxIndex;
    vector<int> path2;
    while (at != -1 && at < n) {
        path2.push_back(at);
        at = path[at] - 1;
    }

    int radius = 1000000000;
    int total = 0;
    for (int i = 0; i < (int)path2.size() - 1; i++) {
        for (int j = 0; j < (int)v[path2[i]].size(); j++) {
            if (v[path2[i]][j].first == path2[i + 1]) {
                total += v[path2[i]][j].second;
                break;
            }
        }
        radius = min(radius, max(total, maxDist - total));
    }

    cout << diameter << endl;
    cout << radius << endl;
}