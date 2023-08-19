#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main () {
    int people, comparisons;
    cin >> people >> comparisons;
    vector<vector<int> > v(people, vector<int>(0, 0));
    for (int i = 0; i < comparisons; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
    }

    int x, y;
    cin >> x >> y;
    x--; y--;

    queue<int> q;
    q.push(x);
    vector<int> visited(people, 0);
    visited[x] = 1;

    while (!q.empty()) {
        int c = q.front();
        q.pop();

        if (c == y) {
            cout << "yes" << endl;
            return 0;
        }

        for (int i : v[c]) {
            if (visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    queue<int> q2;
    q2.push(y);
    vector<int> visited2(people, 0);
    visited2[y] = 1;

    while (!q2.empty()) {
        int c = q2.front();
        q2.pop();

        if (c == x) {
            cout << "no" << endl;
            return 0;
        }

        for (int i : v[c]) {
            if (visited2[i] == 0) {
                q2.push(i);
                visited2[i] = 1;
            }
        }
    }

    cout << "unknown" << endl;
}