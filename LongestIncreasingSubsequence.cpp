#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> dp(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            if (nums[i] > nums[j]) dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
