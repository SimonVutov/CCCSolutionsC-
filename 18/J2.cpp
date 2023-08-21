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
    int n = 0;
    cin >> n;
    string a = "";
    cin >> a;
    string b = "";
    cin >> b;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && a[i] == 'C') t++;
    }
    cout << t << endl;
}