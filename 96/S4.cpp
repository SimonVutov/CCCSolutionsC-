#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

string one[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int two[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500 ,900, 1000};

int toInt (string s) {
    int sum = 0;
    int at = s.length() - 1;
    while (at >= 0) {
        for (int i = 0; i < 13; i++) {
            if (at > 0 && one[i].length() == 2 && s[at - 1] == one[i][0] && s[at] == one[i][1]) {
                sum += two[i];
                at -= 2;
                break;
            } else if (s[at] == one[i][0] && one[i].length() == 1) {
                sum += two[i];
                at--;
                break;
            }
        }
    }

    return sum;
}

string toString (int n) {
    if (n > 1000) return "CONCORDIA CUM VERITATE";
    string s = "";
    while (n > 0) {
        for (int i = 12; i >= 0; i--) {
            if (n >= two[i]) {
                s += one[i];
                n -= two[i];
                break;
            }
        }
    }
    return s;
}

int main () {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string first;
        string second;

        for (int j = 0; j < (int)s.length(); j++) {
            if (s[j] == '+') {
                first = s.substr(0, j);
                second = s.substr(j + 1, s.length() - j - 2);
            }
        }
        cout << first << "+" << second << "=" << toString(toInt(first) + toInt(second)) << "\n";

        //cout << toInt(first) << " " << toInt(second);
    }
}