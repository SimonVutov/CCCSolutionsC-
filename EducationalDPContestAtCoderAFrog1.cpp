#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> v (n);
    for (int j = 0; j < n; ++j) {
        cin >> v[j];
    }
    vector<long long> dp (n);
    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));
    }
    cout << dp[n - 1];
    return 0;
}