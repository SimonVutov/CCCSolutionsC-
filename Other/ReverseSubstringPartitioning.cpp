#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int l; string str;
    cin >> l >> str;
    int s = 0;
    for (int i = 0; i < l - 1; i++) if (str[i] == str[i + 1]) s++;
    if (l - s - 1 == 0) cout << "1" << endl;
    else cout << (str[0] == str[l - 1] ? l - s - 1 : l) << endl;
}