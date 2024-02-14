#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i < n - 1; i++) {
        if (s[i + 1] == '1') s[i] = '0';
    }

    vector<int> spacing;
    bool done = false;
    int cur = 0, total = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cur++;
        else {
            total++;
            if (done) spacing.push_back(cur);
            done = true;
            cur = 0;
        }
    }

    sort(spacing.begin(), spacing.end());

    int at = 0;
    while (spacing[at] <= k && at < (int)spacing.size()) {
        total--;
        k -= spacing[at++];
    }

    if (k > 0 && total == 0) total++;

    cout << total << endl;
}