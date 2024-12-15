#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

bool compare(const pair<long double, int>& x, const pair<long double, int>& y) {
    if (fabs(x.first - y.first) < 1e-9) return x.second < y.second;
    return x.first > y.first;
}

int main() {
    int n, p;
    cin >> n >> p;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<long double, int> > v(n);
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) {
            v[i] = make_pair((long double)(b[i] - a[i]) / (b[i] * (b[i] + 1)), i);
        } else {
            v[i] = make_pair(-1e9, i);
        }
    }

    for (int i = 0; i < p; i++) {
        sort(v.begin(), v.end(), compare);

        int idx = v[0].second;

        if (v[0].first < 0) break;

        a[idx]++;
        b[idx]++;

        v[0].first = (long double)(b[idx] - a[idx]) / (b[idx] * (b[idx] + 1));
    }

    long double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (long double)a[i] / b[i] * 100.0;
    }
    sum /= n;

    cout << fixed << setprecision(10) << sum << endl;

    return 0;
}