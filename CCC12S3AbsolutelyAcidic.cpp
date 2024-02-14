#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v (1001, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a]++;
    }
    int amount1 = -1;
    int amount2 = -1;

    for (int i = 0; i < 1001; i++) {
        if (v[i] > amount1) {
            amount2 = amount1;
            amount1 = v[i];
        } else if (v[i] > amount2) {
            amount2 = v[i];
        }
    }

    int ans = 0;

    if (amount1 - amount2 == 0) {
        int minV = 1001, maxV = 0;
        for (int i = 0; i < 1001; i++) {
            if (v[i] == amount1) {
                minV = min(minV, i);
                maxV = max(maxV, i);
            }
        }

        ans = maxV - minV;
    } else {
        int minV1 = 1001, maxV1 = 0;
        int minV2 = 1001, maxV2 = 0;
        for (int i = 0; i < 1001; i++) {
            if (v[i] == amount1) {
                minV1 = min(minV1, i);
                maxV1 = max(maxV1, i);
            } else if (v[i] == amount2) {
                minV2 = min(minV2, i);
                maxV2 = max(maxV2, i);
            }
        }

        ans = max(maxV2 - minV1, maxV2 - minV1);
    }

    cout << ans << endl;
}
