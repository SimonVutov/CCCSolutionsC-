#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct edge {
    int from, to, length, cost;
    edge (int f, int t, int l, int c) {
        from = f;
        to = t;
        length = l;
        cost = c;
    }
};

int main () {
    int nodes, edges;
    cin >> nodes >> edges;

    int totalCost = 0;

    vector<vector<edge> > n (nodes, vector<edge>());
    for (int i = 0; i < edges; i++) {
        int from, to, length, cost;
        cin >> from >> to >> length >> cost;
        from--; to--;
        n[from].push_back(edge(from, to, length, cost));
        n[to].push_back(edge(to, from, length, cost));
        totalCost += cost;
    }

    vector<int> stack = vector<int>(); //pop_back and back
    int costToSave = 0;

    for (int i = 0; i < nodes; i++) {
        vector<int> distance (nodes, 1000000000);
        vector<int> steps (nodes, 0);

        stack.push_back(i);
        distance[i] = 0;
        while (!stack.empty()) {
            int cur = stack.back();
            stack.pop_back();
            for (int j = 0; j < (int)n[cur].size(); j++) {
                edge e = n[cur][j];
                if (distance[e.to] < distance[cur] + e.length) continue;
                distance[e.to] = distance[cur] + e.length;
                steps[e.to] = steps[cur] + 1;
                stack.push_back(e.to);
            }
        }
        //check if the direct connection is longer than the indirect connection
        for (int j = 0; j < (int)n[i].size(); j++) {
            edge e = n[i][j];
            if (e.length >= distance[e.to] && steps[e.to] > 1) {
                //cout << "Node " << (i+1) << " to " << (e.to+1) << " is " << e.length << " but " << distance[e.to] << " is better" << endl;
                costToSave += e.cost;
            }
        }
    }
    cout << totalCost - costToSave/2 << endl;
}