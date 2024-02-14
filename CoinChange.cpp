#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

vector<int> dp(10001, -1);

int minC(vector<int> &coins, int sum) {
    if (dp[sum] != -1) return dp[sum];
    if (sum == 0) return 0;
    int minAmount = INT_MAX - 1;
    for (int i = 0; i < (int)coins.size(); i++)
        if (sum - coins[i] >= 0)
            minAmount = min(minAmount, minC(coins, sum - coins[i]));
    return dp[sum] = minAmount + 1;
}

int main() {
    int sum, n;
    cin >> sum >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << minC(coins, sum) << endl;
    return 0;
}
