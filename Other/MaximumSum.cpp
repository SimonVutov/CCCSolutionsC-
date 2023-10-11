#include <iostream>
#include <vector>
using namespace std;
//https://dmoj.ca/problem/dp1p1

int maximumSum(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; ++i) { // either include this number or don't
        dp[i] = max(arr[i] + (i >= 2 ? dp[i - 2] : 0), dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    cout << (n == 0 ? 0 : maximumSum(arr)) << endl;
}