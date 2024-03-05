#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

int main() {
    int nodes = 0, edges = 0;
    cin >> nodes >> edges;
    vector<vector<int> > edg(edges, vector<int>(2, 0));
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        edg[i][0] = a;
        edg[i][1] = b;
    }

    vector<int> color(edges, -1);

    for (int i = 0; i < edges; i++) {
        if (edg[i][0] % 2 == 1) {
            color[i] = 0;
        } else {
            color[i] = 1;
        }
    }

    color[edges-1] = -1;

    for (int i = 0; i < edges; i++) {
        if (color[i] == -1) cout << "G";
        else if (color[i] == 0) cout << "B";
        else cout << "R";
    }
}
