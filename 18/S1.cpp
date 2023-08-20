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
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    double s = 1000000000;

    sort(a, a+n);

    int last = a[0];
    for (int i = 1; i < n - 1; i++) {
        double space = a[i+1] - last;
        space /= 2;
        if (space < s) s = space;
        last = a[i];
    }

    cout << fixed << setprecision(1) << s << std::endl;
}