#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
    string ab;
    cin >> ab;
    vector<string> v;
    while (ab[0] != '*') {
        v.push_back(ab);
        cin >> ab; 
    }

    vector<pair<string, char> > stack;
    stack.push_back(make_pair("**", 'A'));
    vector<bool> visited (v.size(), false);
    visited['A' - 'A'] = true;

    while (!stack.empty()) {
        
        char c = stack.back().second;
        string d = stack.back().first;
        stack.pop_back();

        for (int i = 0; i < v.size(); i++) {
            char nc;
            if (d[0] == v[i][0] && d[1] == v[i][1]) continue;

            if (v[i][0] == c) nc = v[i][1];
            else if (v[i][1] == c) nc = v[i][0];
            else continue;
            if (visited[nc - 'A']) continue;
            visited[nc - 'A'] = true;
            stack.push_back(make_pair(v[i], nc));
        }
    }
}