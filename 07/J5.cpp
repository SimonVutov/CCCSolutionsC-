#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>
#include <utility>
using namespace std;

vector<vector<int> > dp (7001, vector<int>(7001, -1));
long minDist, maxDist, n;

long count(vector<int> v, int totalDist, int curDist) {
    if (dp[totalDist][curDist] != -1) return dp[totalDist][curDist];
    long total = 0;
    if (totalDist >= 7000) return 1; //check if it's a valid path, curDist between minDist and maxDist

    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] < totalDist) continue;
        else if (v[i] - curDist >= minDist && v[i] - curDist <= maxDist) {
            total += count(v, v[i], curDist + v[i] - totalDist);
        }
    }
    dp[totalDist][curDist] = total;
    return total;
}

int main () {
    vector<int> v;
    v.push_back(0);
    v.push_back(990);
    v.push_back(1010);
    v.push_back(1970);
    v.push_back(2030);
    v.push_back(2940);
    v.push_back(3060);
    v.push_back(3930);
    v.push_back(4060);
    v.push_back(4970);
    v.push_back(5030);
    v.push_back(5990);
    v.push_back(6010);
    v.push_back(7000);

    cin >> minDist >> maxDist >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    cout << count(v, 0, 0) << endl;
}