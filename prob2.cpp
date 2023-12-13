#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int> > v;

void bfs(int n) {
    queue<pair<int, int> > q;
    q.push({0, 0});
    v[0][0] = 0;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;

        vector<pair<int, int> > moves = {
            {i + 2, j + 1}, {i + 1, j + 2},
            {i - 2, j + 1}, {i - 1, j + 2},
            {i + 2, j - 1}, {i + 1, j - 2},
            {i - 2, j - 1}, {i - 1, j - 2}
        };

        for (const auto& move : moves) {
            int ni = move.first;
            int nj = move.second;
            if (ni >= 0 && ni < n && nj >= 0 && nj < n && v[ni][nj] == -1) {
                v[ni][nj] = v[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    v = vector<vector<int>>(n, vector<int>(n, -1));
    bfs(n);

    vector<int> dists(n * n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dists[v[i][j]]++;
        }
    }

    int maxVal = floor((double)(n * n + 3 * n) / 5);

    if (dists[0] + dists[1] > maxVal) {
        cout << "-1" << endl;
        return 0;
    }

    vector<int> dp(n * n, 0);
    dp[0] = dists[0];
    dp[1] = dists[1];

    for (int i = 2; i < n * n; i++) {
        dp[i] = min(dp[i - 1] + dists[i], min(dp[i - 2] + dists[i], dp[i - 3] + dists[i]));
    }

    vector<int> chosen(n * n, 0);

    int at = n * n - 1;
    while (at >= 0) {
        chosen[at] = 1;
        at -= (at >= 3) ? 3 : ((at >= 2) ? 2 : 1);
    }

    vector<int> numsChosen;

    for (int i = 0; i < n * n; i++) {
        if (chosen[i]) {
            numsChosen.push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (count(numsChosen.begin(), numsChosen.end(), v[i][j]) ? 1 : 0) << " ";
        }
        cout << endl;
    }

    return 0;
}
