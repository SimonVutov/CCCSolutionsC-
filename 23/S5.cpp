#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue> //doesnt work

using namespace std;
vector<int> q;

bool filter (int n, int m) {
    double val = (double)n / (double)m;
    if (val > 1.0/3.0 && val < 2.0/3.0) return false;
    if (val == 0.0 || val == 1.0 || val == 2.0/3.0 || val == 1.0/3.0) {
        q.push_back(m - n);
        return true;
    }
    return val < 1.0/3.0 ? filter(n, m / 3) : filter(n - (2.0/3.0) * m, m);
}

int main () {
    int n;
    cin >> n;
    for (int i = 0; i <= n/2; i++) if (filter(i, n)) cout << i << endl;

    for (int i = 0; i < q.size(); i++) {
        cout << q.back() << endl;
        q.pop_back();
    }
}