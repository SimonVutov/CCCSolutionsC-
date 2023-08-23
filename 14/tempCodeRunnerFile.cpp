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
    if (n % 2) {cout << "bad"; return 0;}
    vector<pair<string, string> > v (n, make_pair("", ""));
    for (int i = 0; i < n; i++) cin >> v[i].first;
    for (int i = 0; i < n; i++) cin >> v[i].second;
    string good = "good";
    for (int i = 0; i < n/2; i++) {
        bool goodHere = false;
        for (int j = i + 1; j < n; j++) {
            if (v[i].first == v[j].second && v[i].second == v[j].first) { goodHere = true; break; }
            if ((v[i].first == v[j].second && v[i].second != v[j].first) || (v[i].first != v[j].second && v[i].second == v[j].first)) { cout << "bad"; return 0; }
            if (v[i].first == v[i].second || v[j].second == v[j].first) { cout << "bad"; return 0; }
            if (v[i].first == v[i].first && v[j].second == v[j].second) { cout << "bad"; return 0; }
        }
        if (!goodHere) good = "bad";
    }

    cout << good;
}