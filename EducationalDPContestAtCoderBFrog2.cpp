#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> v (k);
    for (int j = 0; j < k; ++j) {
        cin >> v[j];
    }
    vector<long long> dp (k);
    for (int i = 0; i < k; i++) {
        dp[i] = abs(v[i] - v[0]);
    }
    for (int i = k; i < n; i++) { //each step
        //calculate the next DP value
        long long next = 1000000000000000000;
        for (int j = 1; j <= k; j++) { //each jump
            if (i - j >= 0) {
                next = min(next, dp[i - j] + abs(v[i] - v[i - j]));
            }
        }
        //move all the values down, in DP and in V
        for (int j = 0; j < k - 1; j++) {
            dp[j] = dp[j + 1];
            v[j] = v[j + 1];
        }
        //add the new value
        dp[k - 1] = next;
        cin >> v[k - 1];
    }
    //print the last value
    long long next = 1000000000000000000;
    for (int j = 1; j <= k; j++) { //each jump
        if (n - 1 - j >= 0) {
            next = min(next, dp[n - 1 - j] + abs(v[n - 1] - v[n - 1 - j]));
        }
    }

    cout << next;
    return 0;
}