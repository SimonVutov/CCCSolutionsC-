#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        v[i] = a[i] * b[i] * c[i];
    }

    vector<int> order (n);
    vector<bool> used (n);
    for (int i = 0; i < n; i++) {
        int best = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (best == -1 || v[j] < v[best])) {
                best = j;
            }
        }
        order[i] = best;
        used[best] = true;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        bool done = false;
        for (int o = 0; o < n; o++) {
            int j = order[o];
            if (x <= a[j] && y <= b[j] && z <= c[j]) {
                cout << v[j] << endl;
                done = true;
            } else if (x <= b[j] && y <= c[j] && z <= a[j]) {
                cout << v[j] << endl;
                done = true;
            } else if (x <= c[j] && y <= a[j] && z <= b[j]) {
                cout << v[j] << endl;
                done = true;
            } else if (x <= a[j] && y <= c[j] && z <= b[j]) {
                cout << v[j] << endl;
                done = true;
            } else if (x <= b[j] && y <= a[j] && z <= c[j]) {
                cout << v[j] << endl;
                done = true;
            } else if (x <= c[j] && y <= b[j] && z <= a[j]) {
                cout << v[j] << endl;
                done = true;
            }

            if (done) {
                break;
            }
        }
        if (!done) {
            cout << "Item does not fit." << endl;
        }
    }
}
