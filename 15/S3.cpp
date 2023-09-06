#include <iostream>
#include <vector>
using namespace std;

int main() {
    int p, n;
    cin >> p >> n;

    vector<int> ps(p + 10, -1);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;

        while (x >= 0 && ps[x] != -1) x--;

        if (x >= 0 && ps[x] == -1) {
            ps[x] = 1;
            ans++;
        } else break;
    }

    cout << ans;
}
