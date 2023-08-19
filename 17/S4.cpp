#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>


using namespace std;

struct Edge {
    int from, to, weight;
    Edge(int f = 0, int t = 0, int w = 0) : from(f), to(t), weight(w) {}
};

vector<Edge> prims (vector<Edge> graph, int nodes) {
    int m = nodes - 1;
    int edgeCount = 0, mstCost = 0;
    vector<Edge> mst (m);
    vector<int> visited(nodes, 0);

    //pq sorted by weight
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq (
        [](Edge a, Edge b) {
            return a.weight > b.weight;
        }
    );

    visited[0] = 1; //speed up by not having to search whole vector
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].from == 0) {
            pq.push(graph[i]);
        }
    }

    while (!pq.empty() && edgeCount != m) {
        Edge e = pq.top();
        pq.pop();

        if (visited[e.to] == 1) continue;
        visited[e.to] = 1;

        mst[edgeCount++] = e;
        mstCost += e.weight;

        for (int i = 0; i < graph.size(); i++) {
            if (visited[graph[i].to] == 1) continue;
            if (graph[i].from == e.to) {
                pq.push(graph[i]);
            }
        }
    }

    if (edgeCount != m) {
        cout << "No MST" << endl;
        return {};
    }

    cout << mstCost << endl;
    return mst;
}

int main () {
    int nodes, edges, enhancer;
    cin >> nodes >> edges >> enhancer;

    vector<Edge> graph;
    for (int i = 0; i < edges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.push_back({from, to, weight});
    }

    vector<Edge> mst;

    mst = prims(graph, nodes);

    //print mst
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].from << " " << mst[i].to << " " << mst[i].weight << endl;
    }
}