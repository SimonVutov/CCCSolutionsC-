#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

long long dp[105][10005][2];
string k;
int d;

int doit(int curSum = 0, int curDigit = 0, bool isLess = false) {
    long long &ans = dp[curSum % d][curDigit][isLess];

    if (ans != -1) return ans;
    if (curDigit == (int)k.size()) return ans = !(curSum % d);
    
    long long sum = 0;
    int limit = isLess ? 9 : k[curDigit] - '0';
    for (int i = 0; i <= limit; ++i) {
        sum += doit((curSum + i) % d, curDigit + 1, isLess || i < limit);
        sum %= 1000000007;
    }

    return ans = sum;
}

int main() {
    cin >> k >> d;
    memset(dp, -1, sizeof(dp));
    cout << (doit() - 1 + 1000000007) % 1000000007 << endl;
}
