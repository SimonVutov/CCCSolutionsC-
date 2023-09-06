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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
        int at = 0;
        for (int j = 0; j < s.length(); j++) {
            if (a[9] != -1) break;
            if (s[j] == '-') continue;
            if (s[j] == 'A' || s[j] == 'a' || s[j] == 'B' || s[j] == 'b' || s[j] == 'C' || s[j] == 'c') { a[at] = 2; at++; }
            else if (s[j] == 'D' || s[j] == 'd' || s[j] == 'E' || s[j] == 'e' || s[j] == 'F' || s[j] == 'f') { a[at] = 3; at++; }
            else if (s[j] == 'G' || s[j] == 'g' || s[j] == 'H' || s[j] == 'h' || s[j] == 'I' || s[j] == 'i') { a[at] = 4; at++; }
            else if (s[j] == 'J' || s[j] == 'j' || s[j] == 'K' || s[j] == 'k' || s[j] == 'L' || s[j] == 'l') { a[at] = 5; at++; }
            else if (s[j] == 'M' || s[j] == 'm' || s[j] == 'N' || s[j] == 'n' || s[j] == 'O' || s[j] == 'o') { a[at] = 6; at++; }
            else if (s[j] == 'P' || s[j] == 'p' || s[j] == 'Q' || s[j] == 'q' || s[j] == 'R' || s[j] == 'r' || s[j] == 'S' || s[j] == 's') { a[at] = 7; at++; }
            else if (s[j] == 'T' || s[j] == 't' || s[j] == 'U' || s[j] == 'u' || s[j] == 'V' || s[j] == 'v') { a[at] = 8; at++; }
            else if (s[j] == 'W' || s[j] == 'w' || s[j] == 'X' || s[j] == 'x' || s[j] == 'Y' || s[j] == 'y' || s[j] == 'Z' || s[j] == 'z') { a[at] = 9; at++; }
            else { a[at] = s[j] - '0'; at++; }
        }

        cout << a[0] << a[1] << a[2] << "-" << a[3] << a[4] << a[5] << "-" << a[6] << a[7] << a[8] << a[9] << endl;
    }
}
