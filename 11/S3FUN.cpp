#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int main () {
    int magSet = 0;
    cin >> magSet;

    for (int yi = 0; yi < pow(5, magSet); yi++) {
        for (int xi = 0; xi < pow(5, magSet); xi++) {
            int mag = magSet;
            int x = xi;
            int y = yi;
            int print = 0;
            while (mag > 0) {
                int xl = x / pow(5, mag - 1);
                int yl = y / pow(5, mag - 1);
                if (xl == 0 || xl == 4 || ((xl == 1 || xl == 3) && (yl > 1)) || (xl == 2 && yl > 2)) {
                    cout << "0";
                    print = 1;
                    mag = 0;
                } else if ((xl > 0 && xl < 4 && yl == 0) || (xl == 2 && yl == 1)) {
                    cout << "1";
                    print = 1;
                    mag = 0;
                } else {
                    x = x % (int)pow(5, mag - 1);
                    y = y % (int)pow(5, mag - 1);
                    mag--;
                }
            }
            if (print == 0 && ((x > 0 && x < 4 && y == 0) || (x == 2 && y == 1))) {
                cout << "1";
            } else if (print == 0) {
                cout << "0";
            }
        }
        cout << endl;
    }
}