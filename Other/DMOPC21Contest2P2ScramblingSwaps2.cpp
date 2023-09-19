#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>
using namespace std;

int main () {
    int n, q;
    cin >> n >> q;

    vector<int> v (n, 0);
    vector<int> location (n + 1, 0);
    for (int i = 0; i < n; i++) { v[i] = i+1; location[i + 1] = i; }

    for (int i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == 'B') {
            int x, y;
            cin >> x >> y;
            swap(v[x-1], v[y-1]);
            location[v[x-1]] = x-1;
            location[v[y-1]] = y-1;
        } else if (c == 'E') {
            int x, y;
            cin >> x >> y;

            int temp = v[location[x]];
            v[location[x]] = v[location[y]];
            v[location[y]] = temp;

            temp = location[x];
            location[x] = location[y];
            location[y] = temp;
        } else if (c == 'Q') {
            vector<int> v2 (n, 0);
            vector<int> v3 (n, 0);
            for (int j = 0; j < n; j++) cin >> v2[j];
            for (int j = 0; j < n; j++) {
                v3[j] = v2[v[j]-1];
            }
            for (int j = 0; j < n; j++) {
                cout << v3[j];
                if (j != n-1) cout << " ";
            }
            cout << endl;
        }
    }
}