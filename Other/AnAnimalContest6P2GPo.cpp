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
    int bands, freinds;
    cin >> bands >> freinds;
    vector<vector<int> > f (freinds, vector<int> (2, 0));
    for (int i = 0; i < freinds; i++) {
        cin >> f[i][0] >> f[i][1];
    }
    vector<int> ans (bands, -1);
    sort(f.begin(), f.end());
    
}