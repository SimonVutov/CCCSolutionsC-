#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string lcs(string a, string b) {
    int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return 0;
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (a[i] == b[j]) dp[i][j] = 1 + dp[i+1][j+1];
            else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    string ans;
    int i = 0, j = 0; //traceback
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            ans += a[i];
            i++;
            j++;
        } else if (dp[i+1][j] > dp[i][j+1]) i++;
        else j++;
    }

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
    return 0;
}
