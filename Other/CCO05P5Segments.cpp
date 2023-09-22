#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set> //doesnt work

using namespace std;

int minSteps (int x, int y, vector<vector<int> > adj, int steps, vector<int> v, vector<vector<int> > vis) {
    cout << x << " " << y << endl;
    int totalSteps = 1000000000;
    vis[x][y] = 1;

    if (y == adj.size() && x == adj.size()) return steps;

    if (adj[x][y] == 1) {
        adj[x][y] = 0;
        v[y - 1]--;
    }

    if (v[y - 1] == 0) {
        totalSteps = minSteps(x, y + 1, adj, steps + 1, v, vis);
    } else {
        if (x > 1 && !vis[x-1][y]) totalSteps = minSteps(x - 1, y, adj, steps + 1, v, vis);
        if (x < adj.size() - 1 && !vis[x+1][y]) totalSteps = min(totalSteps, minSteps(x + 1, y, adj, steps + 1, v, vis));
    }

    return totalSteps;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > adj (n + 1, vector<int> (n + 1, 0));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        adj[a][i + 1] = 1;
        adj[b][i + 1] = 1;
    }

    vector<vector<int> > vis (n + 1, vector<int> (n + 1, 0));
    vis[1][1] = 1;

    cout << minSteps(1, 1, adj, 0, vector<int> (n, 2), vis) << endl;
}