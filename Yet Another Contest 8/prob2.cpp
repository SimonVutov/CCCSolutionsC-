#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    for (const auto& pair : m) {
        int a = pair.first;
        int countA = pair.second;
        int second = x ^ a;

        // Check if 'second' exists in the map and is not the same as 'a' or if 'a' exists more than once
        if ((a != second && m.find(second) != m.end()) || (a == second && countA > 1)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
