#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int n;
string s;
vector<vector<int> > dp (3004, vector<int> (3004, -1));

int howMany(vector<int>& toUse, int at = 0, int lastNum = -1) {
    if (at == n) return 1;
    string key = to_string(at) + to_string(lastNum);
    if (dp[at+1][lastNum+1] != -1) return dp[at+1][lastNum+1];

    int lo = 1, hi = n;
    if (lastNum == -1) lo = 1, hi = n;
    else if (s[at] == '>') hi = lastNum - 1;
    else if (s[at] == '<') lo = lastNum + 1;

    int ans = 0;
    for (int i = lo; i <= hi; i++) {
        if (toUse[i] == 1) continue;
        toUse[i] = 1;
        if (lastNum == -1) ans += howMany(toUse, at, i);
        else ans += howMany(toUse, at + 1, i);
        toUse[i] = 0;

        ans %= 1000000007;
    }

    return dp[at+1][lastNum+1] = ans;
}

int main() {
    cin >> n;
    cin >> s;
    vector<int> toUse (n + 1, 0);
    cout << howMany(toUse) << endl;
}