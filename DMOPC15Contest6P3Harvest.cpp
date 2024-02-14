#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n + 1);
    a[0] = m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        a[from - 1]--;
        a[to]++;
    }

    vector<long long> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] + a[i];
    }

    long long minWidth = 1000000, left = 0, right = 0;
    long long curPotatoes = 0;
    while (right < n) {
        if (curPotatoes < k) {
            curPotatoes += b[right];
            right++;
        } else {
            minWidth = min(minWidth, right - left);
            curPotatoes -= b[left];
            left++;
        }
    }

    while (curPotatoes >= k && left < n) {
        minWidth = min(minWidth, right - left);
        curPotatoes -= b[left];
        left++;
    }

    cout << (minWidth == 1000000 ? -1 : minWidth) << endl;
}
