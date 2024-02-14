#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            int from = min(i, a[i] - 1);
            int to = max(i, a[i] - 1);
            b[from]++;
            b[to + 1]--;
        }
    }

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += b[i];
        ans += (cur != 0);
    }

    cout << ans << endl;
}