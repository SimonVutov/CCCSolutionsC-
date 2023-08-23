#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

vector<vector<int> > a (3, vector<int>(3, 0));
vector<vector<int> > sure (3, vector<int>(3, 1));

bool isValid () {
    for (int i = 0; i < 3; i++) {
        if (a[i][2] - a[i][1] != a[i][1] - a[i][0]) return false;
        if (a[2][i] - a[1][i] != a[1][i] - a[0][i]) return false;
    }

    return true;
}

void base () {
    for (int i = 0; i < 10; i++) {
        for (int i = 0; i < 3; i++) {
            if (sure[i][0] == -1 && sure[i][1] == 1 && sure[i][2] == 1) {
                a[i][0] = a[i][1] - (a[i][2] - a[i][1]);
                sure[i][0] = 1;
            } else if (sure[i][0] == 1 && sure[i][1] == -1 && sure[i][2] == 1) {
                a[i][1] = (a[i][0] + a[i][2]) / 2;
                sure[i][1] = 1;
            } else if (sure[i][0] == 1 && sure[i][1] == 1 && sure[i][2] == -1) {
                a[i][2] = a[i][1] + (a[i][1] - a[i][0]);
                sure[i][2] = 1;
            }

            if (sure[0][i] == -1 && sure[1][i] == 1 && sure[2][i] == 1) {
                a[0][i] = a[1][i] - (a[2][i] - a[1][i]);
                sure[0][i] = 1;
            } else if (sure[0][i] == 1 && sure[1][i] == -1 && sure[2][i] == 1) {
                a[1][i] = (a[0][i] + a[2][i]) / 2;
                sure[1][i] = 1;
            } else if (sure[0][i] == 1 && sure[1][i] == 1 && sure[2][i] == -1) {
                a[2][i] = a[1][i] + (a[1][i] - a[0][i]);
                sure[2][i] = 1;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string s;
            cin >> s;
            if (s[0] == 'X') sure[i][j] = -1;
            else a[i][j] = atoi(s.c_str());
        }
    }

    base();
    if (isValid()) {
        for (int i = 0; i < 3; i++) cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
        return 0;
    }

    while (true) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (!sure[i][j]) {
                    int x = 0;
                    x = rand() % 20;
                    a[i][j] = x;
                    sure[i][j] = 1;
                    base();
                    if (isValid()) {
                        for (int i = 0; i < 3; i++) cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
                        return 0;
                    }
                    sure[i][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
}
