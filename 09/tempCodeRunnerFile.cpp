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

    vector<int> pencilCity(cities + 1, -1);

    for (int i = 0; i < pencilCities; i++) {
        int a, c;
        cin >> a >> c;
        pencilCity[a] = c;
    }

    int s;
    cin >> s;

    vector<int> dist(cities + 1, 1000000000);
    vector<bool> visited(cities + 1, false);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    int minCost = 1000000000;

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        if (pencilCity[c] != -1 && minCost > dist[c] + pencilCity[c]) {
            minCost = dist[c] + pencilCity[c];
        }

        if (visited[c]) {
            continue;
        }
        visited[c] = true;

        for (int i = 0; i < cities + 1; i++) {
            if (graph[c][i] != -1 && dist[i] > dist[c] + graph[c][i]) {
                dist[i] = dist[c] + graph[c][i];
                q.push(i);
            }
        }
    }

    cout << minCost << endl;
}