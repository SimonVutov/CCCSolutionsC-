#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer(vector<int> &v, int x) {
    int skips = 0;
    int res = 0;
    cout << "x: " << x << endl;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] == x) {
            skips += x;
        }
        skips--;

        if (skips < 0) {
            skips = 0;
            cout << " adding " << v[i] << endl;
            res += v[i];
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v (n, 0);
    int tsum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        tsum += v[i];
    }

    vector<int> v2 (k, 0);
    for (int i = 0; i < k; i++) {
        cin >> v2[i];
    }

    vector<int> sum (n+1, 0); // a to b inclusive is sum[b+1] - sum[a]
    for (int i = 0; i < n; i++) {
        sum[i+1] = sum[i] + v[i];
    }
    
    for (int i = 0; i < k; i++) {
        cout << answer(v, v2[i]) << endl;
    }
}
