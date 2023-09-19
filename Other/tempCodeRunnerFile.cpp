#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

vector<string> split(string str, char c) {
    vector<string> v;
    string cur = "";
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] == c) {
            v.push_back(cur);
            cur = "";
        } else {
            cur += str[i];
        }
    }
    v.push_back(cur);
    return v;
}

int main() {
    string str;
    getline(cin, str);
    vector<string> s = split(str, ' ');

    vector<double> v;

    for (int i = 0; i < (int)s.size(); i++) {
        string cur = s[i];
        if (cur == "+" || cur == "-" || cur == "*" || cur == "/" || cur == "%" || cur == "^") {
            int a = v.back();
            v.pop_back();
            int b = v.back();
            v.pop_back();
            if (cur == "+") {
                v.push_back((double)a + (double)b);
            } else if (cur == "-") {
                v.push_back((double)b - (double)a);
            } else if (cur == "*") {
                v.push_back((double)a * (double)b);
            } else if (cur == "/") {
                v.push_back((double)b / (double)a);
            } else if (cur == "%") {
                v.push_back(b % a);
            } else if (cur == "^") {
                v.push_back(pow((double)b, (double)a));
            }
        } else {
            v.push_back(stoi(cur));
        }
    }

    cout << fixed << setprecision(1) << v.back() << endl;
}