#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void printPattern(int a, int b, string c) {
    if (c.length() == a && b == 0) {
        cout << c << endl;
    } else if (c.length() == a && b > 0) {
        return;
    }
    else {
        if (b > 0) printPattern(a, b - 1, c + "1");
        printPattern(a, b, c + "0");
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << "The bit patterns are" << endl;
        printPattern(a, b, "");
        if (i != n - 1) cout << endl;
    }
}
