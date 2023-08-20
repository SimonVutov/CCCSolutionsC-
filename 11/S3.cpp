#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main () {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int mag, x, y;
        cin >> mag >> x >> y;
        int print = 0;
        while (mag > 0) {
            int xl = x / pow(5, mag - 1);
            int yl = y / pow(5, mag - 1);
            if (xl == 0 || xl == 4 || ((xl == 1 || xl == 3) && (yl > 1)) || (xl == 2 && yl > 2)) {
                cout << "empty" << endl;
                print = 1;
                mag = 0;
            } else if ((xl > 0 && xl < 4 && yl == 0) || (xl == 2 && yl == 1)) {
                cout << "crystal" << endl;;
                print = 1;
                mag = 0;
            } else {
                x = x % (int)pow(5, mag - 1);
                y = y % (int)pow(5, mag - 1);
                mag--;
            }
        }
        if (print == 0 && ((x > 0 && x < 4 && y == 0) || (x == 2 && y == 1))) {
            cout << "crystal" << endl;
        } else if (print == 0) {
            cout << "empty" << endl;
        }
    }
}