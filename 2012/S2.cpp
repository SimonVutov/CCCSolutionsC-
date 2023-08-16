#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
    string line;
    cin >> line;

    vector<pair<string, int> > roman;
    roman.push_back(make_pair("I", 1));
    roman.push_back(make_pair("V", 5));
    roman.push_back(make_pair("X", 10));
    roman.push_back(make_pair("L", 50));
    roman.push_back(make_pair("C", 100));
    roman.push_back(make_pair("D", 500));
    roman.push_back(make_pair("M", 1000));

    int total = 0;
    int lastBaseVal = 0;

    for (int i = line.size() - 2; i >= 0 ; i-=2) {
        char ac = line[i];
        int av = ac - '0';
        char bc = line[i + 1];
        string b = bc + "";
        int bv = 0;
        for (int j = 0; j < roman.size(); j++) {
            if (roman[j].first[0] == bc) {
                bv = roman[j].second;
                j = roman.size();
            }
        }
        
        if (bv < lastBaseVal) {
            total -= av * bv;
        } else {
            total += av * bv;
        }
        lastBaseVal = bv;
    }

    cout << total << endl;
}