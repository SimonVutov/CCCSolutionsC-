#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;
    stringstream ss;
    int counter = 1;
    int c = 0;

    while (true) {
        ss << "M";
        c++;
        if (counter++ >= n) break;
        ss << "M";
        c++;
        if (counter++ >= n) break;
        ss << "_";
        if (counter++ >= n) break;
        ss << "_";
        if (counter++ >= n) break;
    }
    cout << c << endl;
    cout << ss.str() << endl;

}