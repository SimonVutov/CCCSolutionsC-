#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        vector<pair<int, int> > v;
        for (int j = 1; j <= x; j++) {
            for (int k = j + 1; k <= x; k++) {
                if (j * k == x) {
                    v.push_back(make_pair(j, k));
                }
            }
        }
        bool printed = false;
        for (int j = 0; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                if ((abs(v[j].first - v[j].second) == abs(v[k].first + v[k].second)) || (abs(v[j].first + v[j].second) == abs(v[k].first - v[k].second))) {
                    cout << x << " is nasty" << endl;
                    printed = true;
                    j = v.size();
                    k = v.size();
                }
            }
        }
        if (!printed) {
            cout << x << " is not nasty" << endl;
        }
    }
}