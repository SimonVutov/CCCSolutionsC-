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
    vector<vector<int> > a(n, vector<int>(n));
    vector<vector<int> > b(n, vector<int>(n));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        bool good = true;

        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n - 1; k++){
                if (a[j][k] < a[j + 1][k] && a[j][k] < a[j][k + 1]) {
                    good = true;
                } else {
                    good = false;
                    k = n; j = n;
                }
            }
        }
        if (good) break;
        else {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++){
                    b[j][k] = a[n - k - 1][j]; // rotate 90 degrees
                }
            }
            a = b;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}