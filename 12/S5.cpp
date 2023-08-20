#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<pair<int, int> > v;
int R, C, n;
vector<vector<int> > dp;

int totalWays(int r, int c) {
    if (r == R && c == C) return 1;
    for (int i = 0; i < n; i++) {
        if (v[i].first == r && v[i].second == c) return 0;
    }
    if (dp[r][c] != 0) return dp[r][c];
    else {
        dp[r][c] += (r < R) ? totalWays(r + 1, c) : 0;
        dp[r][c] += (c < C) ? totalWays(r, c + 1) : 0;
    }
    return dp[r][c];
}

int main () {
    cin >> R >> C >> n;
    for (int i = 0; i < n; i++) {
        int r, c;
        cin >> r >> c;
        v.push_back(make_pair(r, c));
    }
    dp.resize(R + 1, vector<int>(C + 1, 0));
    cout << totalWays(1, 1) << endl;
}