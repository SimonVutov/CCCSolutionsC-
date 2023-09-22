#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int a1, b1, a2, b2;
            cin >> a1 >> b1 >> a2 >> b2;
            bool good = true;
            if (b1 - a1 != b2 - a2) good = false;
            else {
                for (int i = 0; i <= b1 - a1; i++) {
                    if (a[a1 + i - 1] != a[a2 + i - 1]) {
                        good = false;
                        break;
                    }
                }
            }
            if (good) cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if (x == 2) {
            int x, y;
            cin >> x >> y;
            a[x] = y;
        }
    }
}
