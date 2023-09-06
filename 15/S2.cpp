#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
    int j, n;
    cin >> j >> n;

    vector<int> js (j);
    for (int i = 0; i < j; i++) {
        char c;
        cin >> c;
        if (c == 'S') js[i] = 1;
        else if (c == 'M') js[i] = 2;
        else if (c == 'L') js[i] = 3;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'S') {
            if (js[x-1] >= 1) {
                js[x-1] = 0;
                sum++;
            }
        } else if (c == 'M') {
            if (js[x-1] >= 2) {
                js[x-1] = 0;
                sum++;
            }
        } else if (c == 'L') {
            if (js[x-1] >= 3) {
                js[x-1] = 0;
                sum++;
            }
        }
    }

    cout << sum;
}
