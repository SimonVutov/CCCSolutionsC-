#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k, w;
        cin >> n >> k >> w;
        vector<int> p (n+1, 0);
        for (int j = 1; j <= n; j++) cin >> p[j];
        //n pins, k windows, w width of window
        //2D dp, i is bowling balls used and j is the location
        if (w*k >= n) {
            int sum = 0;
            for (int j = 1; j <= n; j++) sum += p[j];
            cout << sum << endl;
            continue;
        }

        vector<int> windows (n - w + 1, 0);

        int l = 0, r = 0, curSum = 0;
        while (r <= n+1) {
            if (r-l < w) {
                curSum += p[r++];
            } else {
                windows[l] = curSum;
                curSum -= p[l++];
            }
        }

        for (int j = 1; j < (int)windows.size(); j++) windows[j-1] = windows[j];
        int lastsum = 0;
        for (int i = n; i > n - w; i--) lastsum += p[i];
        windows[windows.size()-1] = lastsum;

        n = n - w + 1;

        vector<vector<int> > dp (k+1, vector<int> (n+1, 0));
        int maxVal = 0;

        for (int i = 0; i < n; i++) {
            dp[1][i] = windows[i];
            maxVal = max(maxVal, dp[1][i]);
        }

        for (int i = 2; i <= k; i++) {
            int largest = 0;
            for (int j = 2; j < n; j++) {
                if (j - w >= 0) {
                    largest = max(largest, dp[i-1][j-w]);
                    dp[i][j] = max(dp[i][j], largest + windows[j]);//dp[i-1][j]);//windows[j]);
                    maxVal = max(maxVal, dp[i][j]);
                }
            }
        }

        cout << maxVal << endl;
    }
}
