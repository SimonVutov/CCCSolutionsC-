#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

vector<vector<int> > residual(10, vector<int>(10, 0));

void addEdge(int u, int v, int cap) {
    residual[u][v] += cap; // Forward edge
    residual[v][u] += 0;   // Backward edge (initialize to 0)
}

int main () {
    for (int i = 0; i < 8; i++) {
        int units = 0;
        cin >> units;
        addEdge(0, i + 1, units);
    }

    for (int i = 0; i < 8; i++) {
        int units = 0;
        cin >> units;
        addEdge(i + 1, 9, units);
    }

    const int INF = 1e8;
    addEdge(1, 8, INF); // AB+
    addEdge(2, 8, INF);
    addEdge(3, 8, INF);
    addEdge(4, 8, INF);
    addEdge(5, 8, INF);
    addEdge(6, 8, INF);
    addEdge(7, 8, INF);
    addEdge(1, 7, INF); // AB-
    addEdge(3, 7, INF);
    addEdge(5, 7, INF);
    addEdge(7, 7, INF);
    addEdge(1, 6, INF); // B+
    addEdge(2, 6, INF);
    addEdge(5, 6, INF);
    addEdge(6, 6, INF);
    addEdge(1, 5, INF); // B-
    addEdge(5, 5, INF);
    addEdge(1, 4, INF); // A+
    addEdge(2, 4, INF);
    addEdge(3, 4, INF);
    addEdge(4, 4, INF);
    addEdge(1, 3, INF); // A-
    addEdge(3, 3, INF);
    addEdge(1, 2, INF); // O+
    addEdge(2, 2, INF);
    addEdge(1, 1, INF); // O-

    // Ford-Fulkerson, might do Edmonds-Karp later
    int maxFlow = 0;
    while (true) {
        vector<int> parent(10, -1);
        queue<int> q;
        q.push(0);
        parent[0] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == 9) break;
            for (int v = 0; v < 10; v++) {
                if (residual[u][v] > 0 && parent[v] == -1) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        if (parent[9] == -1) break; // No augmenting path
        int pathFlow = INF;
        for (int v = 9; v != 0; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residual[u][v]);
        }
        for (int v = 9; v != 0; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }

    cout << maxFlow << endl;
}