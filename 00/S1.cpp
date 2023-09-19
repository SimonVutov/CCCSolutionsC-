#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <utility>
using namespace std;

int main () {
    int coins, a, b, c;
    cin >> coins >> a >> b >> c;

    // a pays 30 quarters every 35th played
    // b pays 60 quarters every 100th played
    // c pays 9 quarters every 10th played

    int total = 0;
    int on = 0;
    while (coins > 0) {
        if (on == 0) {
            coins--;
            a++;
            if (a == 35) {
                a = 0;
                coins += 30;
            }
        } else if (on == 1) {
            coins--;
            b++;
            if (b == 100) {
                b = 0;
                coins += 60;
            }
        } else if (on == 2) {
            coins--;
            c++;
            if (c == 10) {
                c = 0;
                coins += 9;
            }
        }
        on++;
        if (on == 3) on = 0;
        total++;
    }

    cout << "Martha plays " << total << " times before going broke." << endl;
}