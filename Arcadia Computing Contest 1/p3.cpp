#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string ans, hisAns;
    cin >> ans >> hisAns;

    vector<vector<int> > v(n, vector<int>(2, 0));

    v[0][0] = (ans[0] == hisAns[0]) ? 1 : 0;

    for (int i = 1; i < n; i++) {
        // Case 1: No shift used ever
        v[i][0] = v[i-1][0] + (ans[i] == hisAns[i] ? 1 : 0);

        // Case 2: use shift at this position
        v[i][1] = max(v[i-1][0], v[i-1][1] + (ans[i] == hisAns[i-1] ? 1 : 0));
    }
    cout << max(v[n-1][0], v[n-1][1]) << endl;
}