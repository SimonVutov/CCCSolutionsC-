#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n, c;
    cin >> n >> c;

    vector<long long> h(n), dp(n, 1e18);
    for (int i = 0; i < n; i++) cin >> h[i];
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int l = 0, r = i - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (dp[m] + (h[i] - h[m]) * (h[i] - h[m]) <= dp[m + 1] + (h[i] - h[m + 1]) * (h[i] - h[m + 1])) r = m - 1;
            else l = m + 1;
        }
        int j = l;

        dp[i] = dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + c;
        if (j - 1 >= 0) dp[i] = min(dp[i], dp[j - 1] + (h[i] - h[j - 1]) * (h[i] - h[j - 1]) + c);
        if (j + 1 < i) dp[i] = min(dp[i], dp[j + 1] + (h[i] - h[j + 1]) * (h[i] - h[j + 1]) + c);
    }

    cout << dp[n - 1] << endl;
}
