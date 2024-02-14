#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
vector<long long> sum;

long long sumfrom(int i, int j) {
    if (i == 0) return sum[j];
    return sum[j] - sum[i - 1];
}

long long minC(vector<long long> &a, vector<vector<long long> > &dp, int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != 0) return dp[i][j];

    long long minCost = LONG_LONG_MAX;
    for (int k = i; k < j; k++) {
        minCost = min((long long)minCost, sumfrom(i, j) + minC(a, dp, i, k) + minC(a, dp, k + 1, j));
    }
    dp[i][j] = minCost;
    return minCost;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sum.resize(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) sum[i] = a[i];
        else sum[i] = sum[i - 1] + a[i];
    }

    vector<vector<long long> > dp(n, vector<long long>(n, 0)); //min cost between i and j

    cout << minC(a, dp, 0, n - 1) << endl;
}
