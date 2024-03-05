#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K; // buildings, roads, items
    cin >> N >> M >> K;

    vector<int> itemTimes (K); // time to make each item yourself
    for (int i=0; i<K; i++) cin >> itemTimes[i];

    vector<int> buildingsContaini (K);
    for (int i=0; i<K; i++) cin >> buildingsContaini[i];

    vector<vector<int> > buildingContains (N, vector<int> (0, 0));
    for (int i = 0; i<K; i++) {
        for (int j=0; j<buildingsContaini[i]; j++) {
            int building;
            cin >> building;
            buildingContains[building].push_back(i);
        }
    }

    vector<vector<int> > roads (N, vector<int> (N, 0));
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a][b] = c;
        roads[b][a] = c;
    }

    // minimum spanning tree

    vector<int> minDist (N, 1000000000);
    vector<int> parent (N, -1);
    vector<bool> visited (N, false);

    minDist[0] = 0;
    for (int i=0; i<N; i++) {
        int minIndex = -1;
        for (int j=0; j<N; j++) {
            if (!visited[j] && (minIndex == -1 || minDist[j] < minDist[minIndex])) {
                minIndex = j;
            }
        }
        visited[minIndex] = true;
        for (int j=0; j<N; j++) {
            if (roads[minIndex][j] != 0 && !visited[j] && roads[minIndex][j] < minDist[j]) {
                minDist[j] = roads[minIndex][j];
                parent[j] = minIndex;
            }
        }
    }

    int total = 0;
    for (int i=0; i<N; i++) {
        total += minDist[i];
    }

    cout << total << endl;
}
