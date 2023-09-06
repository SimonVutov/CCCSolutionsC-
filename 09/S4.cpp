#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cities, roads;
    cin >> cities >> roads;
    vector<vector<int> > graph(cities + 1, vector<int>(cities + 1, -1));

    for (int i = 0; i < roads; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }

    int pencilCities;
    cin >> pencilCities;
    vector<pair<int, int> > pencilCity(pencilCities + 1); // city, cost

    for (int i = 0; i < pencilCities; i++) {
        cin >> pencilCity[i].first >> pencilCity[i].second;
    }

    int s;
    cin >> s;

    vector<int> dist(cities + 1, 1e9);
    vector<bool> visited(cities + 1, false);
    dist[s] = 0;

    for (int i = 1; i <= cities; i++) {
        int smallest = 0;
        for (int j = 1; j <= cities; j++) {
            if (!visited[j] && dist[j] < dist[smallest]) {
                smallest = j;
            }
        }
        if (smallest == 0) break;
        visited[smallest] = true;
        for (int j = 1; j <= cities; j++) {
            if (graph[smallest][j] != -1) {
                dist[j] = min(dist[j], dist[smallest] + graph[smallest][j]);
            }
        }
    }

    int minCost = 1e9;
    for (int i = 0; i < pencilCities; i++) {
        minCost = min(minCost, dist[pencilCity[i].first] + pencilCity[i].second);
    }

    cout << minCost << endl;
}
