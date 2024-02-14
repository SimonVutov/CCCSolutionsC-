#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int res(unordered_map<int, int>& memo, vector<int> candies, vector<int> calories, int left, int right) {
    int key = left * 1000007 + right;
    key = key % 1000000007;
    if (memo.find(key) != memo.end()) return memo[key];
    int minDif = 1000000000;
    bool allZero = true;
    for (int i = 0; i < (int)candies.size(); i++) {
        if (candies[i] == 0) continue;
        allZero = false;
        candies[i]--;
        minDif = min(minDif, min(
            res(memo, candies, calories, left + calories[i], right), 
            res(memo, candies, calories, left, right + calories[i])));
        candies[i]++;
    }

    memo[key] = minDif;
    if (allZero) {
        memo[key] = abs(left - right);
        return abs(left - right);
    }
    return minDif;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> candies(n);
    vector<int> calories(n);
    for (int i = 0; i < n; i++) cin >> candies[i] >> calories[i];
    unordered_map<int, int> memo;
    cout << res(memo, candies, calories, 0, 0) << endl;
}
