#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <queue>
using namespace std;

int main() { //1989 2 27 yes, 1989 2 28 no
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (a < 1989) {
            cout << "Yes" << endl;
            continue;
        } else if (a > 1989) {
            cout << "No" << endl;
            continue;
        } else {
            if (b < 2) {
                cout << "Yes" << endl;
                continue;
            } else if (b > 2) {
                cout << "No" << endl;
                continue;
            } else {
                if (c <= 27) {
                    cout << "Yes" << endl;
                    continue;
                } else {
                    cout << "No" << endl;
                    continue;
                }
            }
        }
    }
}
