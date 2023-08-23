#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Wall {
    int a;
    int b;
    int c;
};

int main () {
    int n;
    cin >> n;

    vector<vector<Wall> > walls (n, vector<Wall>()); //walls[i] is all the walls of the ith pen
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int p[m];
        for (int j = 0; j < m; j++) cin >> p[j];
        int cost[m];
        for (int j = 0; j < m; j++) cin >> cost[j];

        for (int j = 0; j < m; j++) {
            Wall w;
            w.a = p[j];
            if (j == m - 1) w.b = p[0];
            else w.b = p[j + 1];
            w.c = cost[j];
            walls[i].push_back(w);
        }
    }

    vector<vector<pair<int, int> > > nodes (n + 1, vector<pair<int, int> >());
    vector<pair<int, int> > conToOut;
    nodes[n].push_back(make_pair(0, 0)); //outside node
    int done[n][800];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) done[i][j] = 0;

    for (int i = 0; i < n; i++) { //for each pen
        for (int j = 0; j < (int)walls[i].size(); j++) { //for each wall in the pen
            bool didntFind = true;
            for (int k = 0; k < n; k++) { //f for each other pen
                for (int l = 0; l < (int)walls[k].size(); l++) { //for each wall in the other pen
                    
                    if (i == k) continue;
                    if (done[i][j] == 1) continue;
                    if ((walls[i][j].a == walls[k][l].a && walls[i][j].b == walls[k][l].b) || (walls[i][j].b == walls[k][l].a && walls[i][j].a == walls[k][l].b)) { // if the walls are the same
                        nodes[i].push_back(make_pair(k, walls[i][j].c));
                        didntFind = false;
                        done[i][j] = 1;
                    }
                }
            }
            if (didntFind) {
                conToOut.push_back(make_pair(i, walls[i][j].c));
            }
        }
    }

    int connectedWithoutOutside = 0;

    //MST without the outside node
    vector<bool> connected (n, 0);
    connected[0] = true;
    int totalCost = 0;
    //you can use priority queue or just loop through all of them
    while (true) { //if every node is connected, break
        int minNode = 0;
        int minCost = 1000000000;
        for (int i = 0; i < (int)nodes.size(); i++) {
            if (connected[i]) {
                for (int j = 0; j < (int)nodes[i].size(); j++) {
                    if (nodes[i][j].second < minCost && !connected[nodes[i][j].first]) {
                        minNode = nodes[i][j].first;
                        minCost = nodes[i][j].second;
                    }
                }
            }
        } //found the next best node above ^
        
        if (minCost == 1000000000) break;
        connected[minNode] = true;
        connectedWithoutOutside++;
        totalCost += minCost;
    }

    for (int i = 0; i < conToOut.size(); i++) {
        nodes[n].push_back(make_pair(conToOut[i].first, conToOut[i].second));
        nodes[conToOut[i].first].push_back(make_pair(n, conToOut[i].second));
    }

    //MST with the outside node
    vector<bool> connected2 (n+1, 0);
    connected2[0] = true;
    int totalCost2 = 0;
    //you can use priority queue or just loop through all of them
    while (true) { //if every node is connected, break
        int minNode = 0;
        int minCost = 1000000000;
        for (int i = 0; i < (int)nodes.size(); i++) {
            if (connected2[i]) {
                for (int j = 0; j < (int)nodes[i].size(); j++) {
                    if (nodes[i][j].second < minCost && !connected2[nodes[i][j].first]) {
                        minNode = nodes[i][j].first;
                        minCost = nodes[i][j].second;
                    }
                }
            }
        } //found the next best node above ^
        
        if (minCost == 1000000000) break;
        connected2[minNode] = true;
        totalCost2 += minCost;
    }

    //cout << totalCost << " " << totalCost2 << " " << connectedWithoutOutside << endl;

    if (connectedWithoutOutside != n - 1) totalCost = totalCost2;
    cout << min(totalCost, totalCost2) << endl;
}