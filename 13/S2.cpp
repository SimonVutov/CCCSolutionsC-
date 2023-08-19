#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int max = 0, n = 0;
    cin >> max >> n;

    int cur = 0;

    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        v[i] = x;
    }

    for (int i = 0; i < n; i++) {
        cur += v[i];
        if (i >= 4) cur -= v[i - 4];
        if (cur > max) {
            cout << i << endl;
            return 0;
        }
    }

    cout << n << endl;
}