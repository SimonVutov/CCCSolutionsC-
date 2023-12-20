#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string recursion(vector<string>& v) {
    int n = v.size();
    if (n == 1) {
        return v[0];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == "X") {
            string x = "(" + v[i - 1] + " X " + v[i + 1] + ")";
            v.erase(v.begin() + i - 1, v.begin() + i + 2);
            v.insert(v.begin() + i - 1, x);
            return recursion(v);
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == "+" || v[i] == "-") {
            string x = "(" + v[i - 1] + " " + v[i] + " " + v[i + 1] + ")";
            v.erase(v.begin() + i - 1, v.begin() + i + 2);
            v.insert(v.begin() + i - 1, x);
            return recursion(v);
        }
    }
    return "ERROR";
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // to consume the newline character after reading n

    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        vector<string> v;
        for (int j = 0; j < (int)str.length(); ++j) {
            if (str[j] == ' ') {
                v.push_back(str.substr(0, j));
                str = str.substr(j + 1);
                j = 0;
            }
        }
        v.push_back(str); // Add the last substring

        cout << recursion(v).substr(1, recursion(v).length() - 2) << endl;
        if (i != n - 1) {
            cout << endl;
        }
    }

    return 0;
}
