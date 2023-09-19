#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int sz, trees;
    cin >> sz >> trees;
    vector<pair<int, int> > v (trees, make_pair(0, 0));
    for (int i = 0; i < trees; i++) cin >> v[i].first >> v[i].second;

    //add trees around the border
    for (int i = 0; i < sz; i++) {
        v.push_back(make_pair(i, -1));
        v.push_back(make_pair(i, sz));
        v.push_back(make_pair(-1, i));
        v.push_back(make_pair(sz, i));
    }

    int largest = 0;

    for (int i = 0; i < (int)v.size(); i++) { // tree i
        for (int j = 0; j < (int)v.size(); j++) { // tree j
            if (i == j) continue;

            int topLeftX = v[i].first + 1;
            int topLeftY = v[j].second + 1;
            int size = 1000000;
            size = min(size, sz - topLeftX);
            size = min(size, sz - topLeftY);

            for (int k = 0; k < trees; k++) {
                if (k == i || k == j) continue;
                if (v[k].first < topLeftX || v[k].second < topLeftY) continue;

                // for each tree, if the tree is inside the square, then make the square smaller to fit
                if (v[k].first >= topLeftX && v[k].first <= topLeftX + size && v[k].second >= topLeftY && v[k].second <= topLeftY + size) {
                    size = min(size, max(v[k].first - topLeftX, v[k].second - topLeftY));
                }
            }

            if (size > largest) largest = size;
        }
    }
    cout << largest << endl;
}