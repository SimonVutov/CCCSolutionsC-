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
        int x;
        cin >> x;
        int L0=x, L1=0, L2=0;

        int r = 0;
        while (true) {
            cout << "Round " << r << ": " << L0 << " undefeated, " << L1 << " one-loss, " << L2 << " eliminated" << "\n";
            int oldL0 = L0, oldL1 = L1, oldL2 = L2;
            if (L0 == 1) {
                L2 += L1/2;
                L1 -= L1/2;
                L0--;
                L1++;
            } else {
                L2 += L1/2;
                L1 -= L1/2;
                L1 += L0/2;
                L0 -= L0/2;
            }
            if (oldL0 == L0 && oldL1 == L1 && oldL2 == L2) {
                cout << "There are " << r << " rounds. " << "\n";
                return 0;
            }

            r++;
        }
    }
}