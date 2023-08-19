#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int y = 0;
    cin >> y;
    while (true) {
        y++;
        string s = to_string(y);
        vector<int> v(10, 0);
        bool flag = true;
        for (int i = 0; i < s.size(); i++) {
            v[s[i] - '0']++;
            if (v[s[i] - '0'] > 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << y << endl;
            break;
        }
    }
}