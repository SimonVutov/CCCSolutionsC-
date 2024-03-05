#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    //check 4
    if (a == b && b == c && c == d) {
        cout << "4" << endl;
        return 0;
    }

    //check 3
    if (((a + b) / 2 == c && c == d) || ((a + c) / 2 == b && b == d) || ((b + d) / 2 == a && a == c) || ((c + d) / 2 == a && a == b)) {
        cout << "3" << endl;
        return 0;
    }
    //check 2
    if ((a + b == c + d) || (a + c == b + d) || ((a + b + c)/3 == d) || ((a + b + d)/3 == c) || ((a + c + d)/3 == b) || ((b + c + d)/3 == a)) {
        cout << "2" << endl;
        return 0;
    }

    //check 1
    cout << "1" << endl;
    return 0;
}
