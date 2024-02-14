#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int maxAns = 0;

        for (int j = 0; j < n; j++) {
            char letter = s[j + 1];

            int l = j - 1;
            while (l >= 0 && s[l] == letter) {
                l--;
            }

            int r = j + 1;
            while (r < n && s[r] == letter) {
                r++;
            }

            maxAns = max(maxAns, r - l - 1);
        }

        for (int j = 0; j < n; j++) {
            char letter = s[j - 1];

            int l = j - 1;
            while (l >= 0 && s[l] == letter) {
                l--;
            }

            int r = j + 1;
            while (r < n && s[r] == letter) {
                r++;
            }

            maxAns = max(maxAns, r - l - 1);
        }

        cout << maxAns << endl;
    }
}
