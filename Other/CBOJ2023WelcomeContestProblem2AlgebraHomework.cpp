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

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c && b == d) cout << "INFINITE" << endl;
        else if (a == c && b != d) cout << "0" << endl;
        else cout << "1" << endl;
    }
}