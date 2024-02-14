#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    vector<vector<int> > dp (m + 1, vector<int>(n + 1, 0));
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (text1[i] == text2[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}

int main() {
    string s;
    cin >> s;
    cout << 26 - longestCommonSubsequence(s, "abcdefghijklmnopqrstuvwxyz") << endl;
    return 0;
}