#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> dp; //WHY DOESNT MAP WORK!?!??!

long long subtrees(int n){
    if (dp[n]) return dp[n];
    if (n == 1) return 1;

    int k = n;
    while (k >= 2) {
        int x = n / k, nn = n / (x + 1);
        dp[n] += (k - nn) * subtrees(x);
        k = nn;
    }
    return dp[n];
}

int main () {
    int n = 0;
    cin >> n;
    dp[1] = 1;
    cout << subtrees(n);
}