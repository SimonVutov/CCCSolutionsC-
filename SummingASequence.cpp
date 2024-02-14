#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (n == 1) {
        cout << max((long long)0, (long long)arr[0]) << endl;
        return 0;
    }

    if (n == 2) {
        cout << max((long long)0, (long long)max(arr[0], arr[1])) << endl;
        return 0;
    }

    vector<long long> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }

    cout << max((long long)0, dp[n - 1]) << endl;
}
