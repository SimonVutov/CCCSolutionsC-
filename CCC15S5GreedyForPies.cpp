#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp [3001][2][101][101];
vector<int> a, b;
int n, m;

long long solve (int N, int canTake, int i, int j) {
    if (dp[N][canTake][i][j] != -1) return dp[N][canTake][i][j];
    long long ans = 0;

    if (N == n) { // if at end of line
        if (i <= j) {
            if (canTake) ans = max(ans, b[j] + solve(N, 0, i, j-1));
            else ans = max(ans, solve(N, 1, i+1, j));
        } else ans = 0;
        return dp[N][canTake][i][j] = ans;
    }

    if (canTake) { // take this, take from bag, skip
        ans = max(ans, a[N] + solve(N + 1, 0, i, j));
        if (i <= j) ans = max(ans, b[j] + solve(N, 0, i, j-1));
        ans = max(ans, solve(N, 0, i, j)); // same as solve(N + 1, 1, i, j)
    } else { // insert from bag, skip
        if (i <= j) ans = max(ans, solve(N, 1, i+1, j));
        ans = max(ans, solve(N+1, 1, i, j));
    }

    return dp[N][canTake][i][j] = ans;
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(b.begin(), b.end());
    memset(dp, -1, sizeof dp);

    if (m > 0) cout << solve(0, 1, 0, m-1) << endl;
    else cout << solve(0, 1, 1, 0) << endl;
}
