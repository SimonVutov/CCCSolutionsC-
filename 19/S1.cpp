#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;
    int a[2][2] = {{1, 2}, {3, 4}};

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'H') {
            swap(a[0][0], a[1][0]);
            swap(a[0][1], a[1][1]);
        } else {
            swap(a[0][0], a[0][1]);
            swap(a[1][0], a[1][1]);
        }
    }

    cout << a[0][0] << " " << a[0][1] << endl;
    cout << a[1][0] << " " << a[1][1] << endl;
}
