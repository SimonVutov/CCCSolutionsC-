#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int ans(vector<int> v, int maxV = 1000000000, int at = 0) {
    int n = v.size();
    if (at >= n) {
        return 1;
    }
    int sends = 1000000;
    //either take this one, only if it is less than maxV
    if (v[at] <= maxV) {
        sends = ans(v, v[at], at + 1);
    }
    //or dont take, and send a new ans with maxV as the val of that height so that we dont lower our current maxV
    sends = min(sends, 1 + ans(v, v[at], at + 1));
    //we kill the current one


    return sends;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> v (n);
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }

        cout << ans(v);
    }
    return 0;
}