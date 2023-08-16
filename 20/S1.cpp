#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    vector< pair<double, double> > v; //time, location

    for (int i = 0; i < n; i++) {
        int t = 0, l = 0;
        cin >> t >> l;
        v.push_back(make_pair(t, l));
    }

    sort(v.begin(), v.end());

    double max = 0;
    for (int i = 0; i < (int)v.size() - 1; i++) {
        double speed = 0;
        speed = abs( (double)(v[i].second - v[i+1].second) / (double)(v[i+1].first - v[i].first) );
        max = (speed > max) ? speed : max;
    }

    cout << max << endl;
}