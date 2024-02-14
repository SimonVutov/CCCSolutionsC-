#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
const int MOD = 1e9 + 7;
unordered_map<int, int> dp;
vector<vector<int> > a(21, vector<int>(21));

int countMatches (int i, int ID) {
    if (dp.find(ID) != dp.end()) return dp[ID];
    if (i == n) return dp[ID] = 1;

    int ans = 0;

    for (int j = 0; j < n; j++) {
        if (!(ID & (1 << j)) || a[i][j] != 1) continue;
        ans += countMatches(i + 1, ID & ~(1 << j));
        ans %= MOD;
    }

    return dp[ID] = ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    int initialBitmask = (1 << n) - 1;
    cout << countMatches(0, initialBitmask) << endl;
}
