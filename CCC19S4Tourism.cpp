#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> dp (1000001, -1);

int maxv (vector<int> v, int l, int r) {
    int max = 0;
    for (int i = l; i <= r; i++) {
        if (v[i] > max) max = v[i];
    }
    return max;
}

long long solve(int index) {
    return 0;
}

int main() {
    int nums, perDay;
    cin >> nums >> perDay;
    vector<int> attractions(nums, -1);
    for (int i = 0; i < nums; i++) cin >> attractions[i];

    for (int i = 0; i < nums; i++) {
        if ((i+1) % perDay == 0) {
            if (i - perDay >= 0) {
                dp[i] = maxv(attractions, i - perDay, i) + dp[i - perDay];
            } else {
                dp[i] = maxv(attractions, 0, i);
            }
            cout  << "changed: " << i << " to " << dp[i] << endl;
        }
    }

    for (int i = 0; i < 20; i++) cout << dp[i] << " ";
    //print v
    for (int i = 0; i < nums; i++) cout << attractions[i] << " ";

    //cout << dp[nums - 1] << endl;
}
