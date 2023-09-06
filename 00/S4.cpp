#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;

vector<int> dp (6000, -1);
vector<int> v;

int MinShots (int d, int hits = 0) {
    if (d == 0) return 0;
    if (dp[d] != -1) return dp[d];
    
    dp[d] = 1000000000;

    for (int i = 0; i < (int)v.size(); i++) {
        if (d - v[i] >= 0) dp[d] = min(dp[d], MinShots(d - v[i], hits + 1) + 1);
    }
    return dp[d];
}

int main() {
    int d, n;
    cin >> d >> n;

    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = MinShots(d);
    if (ans == 1000000000) cout << "Roberta acknowledges defeat." << endl;
    else cout << "Roberta wins in " << ans << " strokes." << endl;
}