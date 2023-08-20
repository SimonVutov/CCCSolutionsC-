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

int main () {
    vector<pair<int, int> > v;
    int count = 0;
    vector<bool> done (7, false);
    int a, b;
    cin >> a;
    cin >> b;
    while (a != 0 && b != 0) {
        v.push_back(make_pair(a, b));

        cin >> a;
        cin >> b;
    }

    v.push_back(make_pair(1, 7));
    v.push_back(make_pair(1, 4));
    v.push_back(make_pair(2, 1));
    v.push_back(make_pair(3, 4));
    v.push_back(make_pair(3, 5));

    stringstream ss;

    int counter = 0;

    while (count < 7 && counter < 100) {
        counter++;
        for (int i = 1; i <= 7; i++) { //check first task, then second, etc. if placeable
            if (done[i]) continue;
            bool goodToPlaceI = true;
            for (int j = 0; j < v.size(); j++) { //check if a different task is needed before this task
                if (v[j].second == i) goodToPlaceI = false;
            }
            if (goodToPlaceI) {
                ss << i << " ";
                done[i] = true;
                count++;
                for (int j = 0; j < v.size(); j++) { //erase condition to have this task before, since we have it now
                    if (v[j].first == i) { v.erase(v.begin() + j); j--; }
                }
                i = 8;
            }
        }
    }

    if (count == 7) {
        cout << ss.str() << endl;
    } else {
        cout << "Cannot complete these tasks. Going to bed." << endl;
    }
}