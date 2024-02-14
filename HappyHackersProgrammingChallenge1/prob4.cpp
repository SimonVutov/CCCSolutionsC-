#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    unordered_map<long long, long long> m;
    int T;
    cin >> T;

    while (T--) {
        long long c, count = 0;
        cin >> c;

        if (m.find(c) != m.end()) {
            cout << m[c] * 2 - 1 << endl;
            continue;
        }

        for (long long a = c + 1; a <= 2 * c; a++) {
            count += ((a * c) % (a - c) == 0);
        }

        m[c] = count;
        cout << count * 2 - 1 << endl;
    }

    return 0;
}