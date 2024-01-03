#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        vector<int> v (n, 0), res (n, 0);
        for (int j = 0; j < n; j++) cin >> v[j];
        sort(v.begin(), v.end());

        if (n % 2 == 0) {
            if (v[0] == v[n-1]) {
                cout << -1 << endl;
                continue;
            }
            int a = 0, b = n/2;
            for (int j = 0; j < n; j++) {
                if (j % 2 == 1) res[j] = v[a++];
                else res[j] = v[b++];
            }
        } else {
            for (int j = 0; j < n; j++) {
                cout << v[j];
                if (j < n - 1) cout << " ";
            }
            cout << endl;
            continue;
        }
        
        for (int j = 0; j < n; j++) {
            cout << res[j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }
}