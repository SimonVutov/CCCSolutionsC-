#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n+2), r(n+2);
    vector<vector<int> > dp(n+5, vector<int>(2, -1));
    l[0] = r[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        dp[i][0] = r[i] - l[i] + min(dp[i-1][0] + abs(l[i-1] - r[i]), dp[i-1][1] + abs(r[i-1] - r[i])) + 1;
        dp[i][1] = r[i] - l[i] + min(dp[i-1][0] + abs(l[i-1] - l[i]), dp[i-1][1] + abs(r[i-1] - l[i])) + 1;
    }
    cout << min(dp[n][0] + (n - l[n]), dp[n][1] + (n - r[n]))-1 << endl;
}