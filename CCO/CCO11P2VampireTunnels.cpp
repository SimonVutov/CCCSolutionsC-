#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

struct CompareDistance {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first; // Compare by distance, smaller distances come first
    }
};

int main () {
    int S, P, E; //seconds above ground, points, edges
    cin >> S >> P >> E;

    vector<vector<pair<int, int> > > adj (P, vector<pair<int, int> > (P, make_pair(0, 0)));
    //distance, above/below (1/0)
    for (int i = 0; i < E; i++) {
        int a, b, d, t;
        cin >> a >> b >> d >> t;
        adj[a][b] = make_pair(d, t);
        adj[b][a] = make_pair(d, t);
    }

    vector<int> distance (P, 1000000000);
    vector<int> aboveGround (P, 0);
    priority_queue<pair<int, int>, vector<pair<int, int> >, CompareDistance> pq;
    //distance, node
    pq.push(make_pair(0, 0));
    distance[0] = 0;
    aboveGround[0] = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int cDist = cur.first;
        int cNode = cur.second;

        for (int i = 0; i < P; i++) {
            int nEdgeDist = adj[cNode][i].first;
            int nAbove = adj[cNode][i].second;
            int nTimeAbove = aboveGround[cNode] + (nAbove ? nEdgeDist : 0);
            int nTotalDist = distance[cNode] + nEdgeDist;

            if (nEdgeDist != 0 && distance[i] > nTotalDist && nTimeAbove <= S) {
                pq.push(make_pair(nTotalDist, i));
                distance[i] = nTotalDist;
                aboveGround[i] = nTimeAbove;
            }
        }
    }
    cout << (distance[P - 1] == 1000000000 ? -1 : distance[P - 1]);
}