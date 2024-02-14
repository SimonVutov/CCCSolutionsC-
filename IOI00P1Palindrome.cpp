#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>

using namespace std;

// Custom hash function for std::pair<int, int>
struct pair_hash {
    inline std::size_t operator()(const std::pair<int, int>& v) const {
        return std::hash<int>()(v.first) ^ std::hash<int>()(v.second);
    }
};

unordered_map<pair<int, int>, int, pair_hash> dp;

bool isPalindrome(const string &s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int minRemoves(const string &s, int start, int end) {
    auto key = make_pair(start, end);
    if (dp.find(key) != dp.end()) return dp[key];

    if (isPalindrome(s, start, end)) return 0;

    int minV = INT_MAX;
    for (int i = start; i <= end; i++) {
        int left = i > start ? minRemoves(s, start, i - 1) : 0;
        int right = i < end ? minRemoves(s, i + 1, end) : 0;
        minV = min(minV, 1 + left + right);
    }

    dp[key] = minV;
    return minV;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << minRemoves(s, 0, s.length() - 1) << endl;
}
