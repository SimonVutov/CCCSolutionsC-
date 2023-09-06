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
    int c, r;
    cin >> c >> r;
    int x, y;
    cin >> x >> y;

    int xPos = 0, yPos = 0;

    while (x != 0 || y != 0) {
        xPos = xPos + x;
        if (xPos < 0) xPos = 0;
        if (xPos > c) xPos = c;
        yPos = yPos + y;
        if (yPos < 0) yPos = 0;
        if (yPos > r) yPos = r;
        
        cout << xPos << " " << yPos << endl;
        cin >> x >> y;
    }
}
