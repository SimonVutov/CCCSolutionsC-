#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

int main() {
    int nodes = 0, edges = 0; // N, M
    cin >> nodes >> edges;
    vector<vector<int> > edg(edges, vector<int>(2, 0));
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edg[i][0] = a;
        edg[i][1] = b;
    }

    vector<int> connected(nodes, 0);
    vector<int> connectedEdges (edges, 0);
    connected[0] = 1;

    for (int i = 0; i < edges; i++) {
        if (connected[edg[i][0]] == 1 && connected[edg[i][1]] == 0) {
            connected[edg[i][1]] = 1;
            connectedEdges[i] = 1;
        }
        if (connected[edg[i][1]] == 1 && connected[edg[i][0]] == 0) {
            connected[edg[i][0]] = 1;
            connectedEdges[i] = 1;
        }
    }

    for (int i = 0; i < nodes; i++) {
        if (connected[i] == 1) {
            cout << "C";
        }
        else {
            cout << "P";
        }
    }

    cout << endl;

    for (int i = 0; i < edges; i++) {
        if (connectedEdges[i] == 1) {
            cout << "C";
        }
        else {
            cout << "P";
        }
    }

    cout << endl;
}
