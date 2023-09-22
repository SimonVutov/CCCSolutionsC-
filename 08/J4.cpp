#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <iomanip>
using namespace std; //doesnt work, idk why

string toPost(string pre) {
    if (pre.length() == 1) return pre;

    if (pre[1] == '+' || pre[1] == '-')
        return toPost(pre.substr(1, pre.length() - 2)) + pre[pre.length() - 1] + pre[0];
    return pre[1] + toPost(pre.substr(2, pre.length() - 1)) + pre[0];
}

int main() {
    string s;
    getline(cin, s);
    vector<string> v;
    while (s != "0") {
        string pre = "";
        for (int i = 0; i < (int)s.length(); i+= 2) pre = pre + s[i];
        v.push_back(toPost(pre));
        getline(cin, s);
    }

    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = 0; j < (int)v[i].length(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}