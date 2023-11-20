#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1 (n1), v2 (n2);
    for (int i = 0; i < n1; i++) cin >> v1[i];
    for (int i = 0; i < n2; i++) cin >> v2[i];
    vector<vector<int> > dp (n1 + 1, vector<int> (n2 + 1, 0));
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            if (v1[i] == v2[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[0][0] << endl;
}