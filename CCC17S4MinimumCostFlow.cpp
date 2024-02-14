#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, D;

struct Edge {
    int from, to, cost, usedInitially, usedFinally;
};

bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

int main() {
    cin >> N >> M >> D;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
        if (i < N - 1) {
            edges[i].usedInitially = 1;
        }
    }

    unordered_map<int, int> used;
    used[1] = 1;

    for (int i = 0; i < N - 1; i++) {
        int selectedID = -1;
        for (int j = 0; j < M; j++) {
            if ((used[edges[j].from] == 1 && used[edges[j].to] == 0) || (used[edges[j].from] == 0 && used[edges[j].to] == 1)) {
                if (selectedID == -1 || edges[j].cost < edges[selectedID].cost) {
                    selectedID = j;
                }
            }
        }
        used[edges[selectedID].from] = 1;
        used[edges[selectedID].to] = 1;
        edges[selectedID].usedFinally = 1;
    }

    int turnedOn = 0;
    int turnedOff = 0;

    for (int i = 0; i < M; i++) {
        if (edges[i].usedFinally == 1) {
            if (edges[i].usedInitially == 0 && edges[i].usedFinally == 1) {
                turnedOn++;
            }
            if (edges[i].usedInitially == 1 && edges[i].usedFinally == 0) {
                turnedOff++;
            }
        }
    }

    cout << turnedOff << " " << turnedOn << endl;
    cout << max(turnedOn, turnedOff) << endl;
}
