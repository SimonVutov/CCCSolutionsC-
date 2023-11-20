#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;

int main () {
    int n;
    string s;
    cin >> n >> s;
    if (s[0] != s[n - 1]) {
        cout << n;
        return 0;
    }
    int t = 1;
    for (int i = 1; i < n; i++) if (s[i] == s[i - 1]) t++;
    cout << n - t;
}