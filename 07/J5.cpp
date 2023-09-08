#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <utility>
using namespace std;

int minDist, maxDist;

int count(vector<int> v, int distTotal, int distCurr) {
    int total = 0;
    if (distTotal > 7000) return 1;

    for (int i = 0; i < v.size(); i++) {
        distTotal += v[i];
        distCurr = v[i];
        if (distCurr >= minDist && distCurr <= maxDist) {
            total += count(v, distTotal, distCurr);
        }
    }

    if (distTotal >= minDist && distTotal <= maxDist) total++;

    return total;
}

int main () {
    vector<int> v = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};

    cin >> minDist >> maxDist;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    cout << count(v, 0, 0) << endl;
}