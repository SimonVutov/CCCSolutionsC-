#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> h (N, 0), a (N, 0);
    for (int i = 0; i < N; i++) cin >> h[i];
    for (int i = 0; i < N; i++) cin >> a[i];

    long long maxV = 0;

    vector<long long> dp (N, 0);
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j < N; j++) {
            if (h[i] <= h[j]) dp[i] = max(dp[i], dp[j] + a[i]);
            maxV = max(maxV, dp[i]);
        }
    }

    cout << maxV << endl;
    return 0;
}