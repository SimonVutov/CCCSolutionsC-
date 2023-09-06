#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>
using namespace std;

int main () {
    int n, q;
    cin >> n >> q;
    deque<pair<int, int> > dq; // (first, second) index

    for (int i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == 'B') {
            int x, y;
            cin >> x >> y;
            dq.push_front(make_pair(x, y));
        } else if (c == 'E') {
            int x, y;
            cin >> x >> y;
            dq.push_back(make_pair(x, y));
        } else if (c == 'Q') {
            vector<int> v (n, 0);
            for (int j = 0; j < n; j++) cin >> v[j];
            for (int j = (int)dq.size() - 1; j >= 0; j--)
                swap(v[dq[j].first-1], v[dq[j].second-1]);
            for (int j = 0; j < n; j++) cout << v[j] << " ";
            cout << endl;
        }
    }
}