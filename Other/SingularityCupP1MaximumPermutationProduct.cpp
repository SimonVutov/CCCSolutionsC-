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

    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    if (n > 10) {
        if (v[0] == 1) {
            cout << "2 " << n << endl;
            return 0;
        } else if (v[n-1] == 1) {
            cout << "1 " << n-1 << endl;
            return 0;
        } else {
            cout << "1 " << n << endl;
            return 0;
        }
    }

    double s1 = 1, s2 = 1, s3 = 1;
    int midID = -1;

    for (int i = 0; i < n; i++) {
        s3 *= v[i];
        if (v[i] == 1) {
            midID = i;
        }
    }
    for (int j = 0; j < midID; j++) s1 *= v[j];
    for (int j = midID+1; j < n; j++) s2 *= v[j];

    if (midID != 0) s1 /= midID;
    if (midID != n - 1) s2 /= n - midID - 1;
    s3 /= n;

    if (s1 > s2 && s1 > s3 && midID != 0) {
        cout << "1 " << midID << endl;
    } else if (s2 > s1 && s2 > s3 && midID != n - 1) {
        cout << midID+2 << " " << n << endl;
    } else {
        cout << "1 " << n << endl;
    }
}