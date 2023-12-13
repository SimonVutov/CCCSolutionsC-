#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool is_digits(const string &str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

int calc (string str) {
    int n = str.length();
    if (is_digits(str)) return stoi(str);

    if (str[n-1] == ')') {
        int open = 0;
        for (int i = n-2; i >= 0; i--) {
            if (str[i] == '(' && open == 0) {
                cout << "found at " << i << endl;
                cout << str.substr(0, i) << endl;
                cout << " " << str.substr(i+1, n-i-2) << endl;
                str = str.substr(0, i) + to_string(calc(str.substr(i+1, n-i-2)));
                break;
            }
            if (str[i] == ')') open++;
            else if (str[i] == '(') open--;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!is_digits(str.substr(i+1))) continue;
        if (str[i] == '<') return calc(str.substr(0, i)) * stoi(str.substr(i+1)) * 1.5;
        if (str[i] == '>') return stoi(str.substr(i+1)) == 0 ? 0 : (calc(str.substr(0, i)) + 6) / stoi(str.substr(i+1));
        if (str[i] == '~') return calc(str.substr(0, i)) * calc(str.substr(0, i)) + stoi(str.substr(i+1));
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s = "";
        cin >> s;
        cout << calc(s) << endl;
    }
}
