#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int x, y, z;
    cin >> n >> x >> y >> z;
    
    vector<int> dp(100005, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;

        if (i - x >= 0 && dp[i - x] != -1) {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i - y >= 0 && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i - z >= 0 && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    cout << dp[n] << endl;
}
