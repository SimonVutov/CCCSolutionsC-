#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int main () {
    int m, q;
    cin >> m >> q;
    vector<pair<char, char> > roads (m, make_pair(' ', ' '));
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        roads[i] = make_pair(a[0], b[0]);
    }

    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        char Ac = a[0];
        char Bc = b[0];

        vector<bool> visited (30, false);
        vector<char> prev(30, ' ');

        queue<char> q;
        q.push(Ac);
        visited[Ac - 'A'] = true;

        while (!q.empty()) {
            char cur = q.front();
            q.pop();

            for (int i = 0; i < m; i++) {
                if (roads[i].first == cur && !visited[roads[i].second - 'A']) {
                    q.push(roads[i].second);
                    visited[roads[i].second - 'A'] = true;
                    prev[roads[i].second - 'A'] = cur;
                } else if (roads[i].second == cur && !visited[roads[i].first - 'A']) {
                    q.push(roads[i].first);
                    visited[roads[i].first - 'A'] = true;
                    prev[roads[i].first - 'A'] = cur;
                }
            }
        }

        vector<char> path;
        char at = Bc;
        while (at != ' ' && at != Ac) {
            path.push_back(at);
            at = prev[at - 'A'];
        }
        path.push_back(Ac);

        for (int i = path.size() - 1; i >= 0; i--) cout << path[i];
        cout << "\n";
    }
}