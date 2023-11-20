#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int occurances (string main, string sub) {
    if (sub.length() == 0) return 1;
    int total = 0;
    for (int i = 0; i < main.length(); i++) {
        if (main[i] == sub[0]) total += occurances(main.substr(i + 1), sub.substr(1));
    }
    return total;
}

int main () {
    int n;
    string s;
    cin >> n >> s;

    cout << occurances(s, "amis") << endl;
}