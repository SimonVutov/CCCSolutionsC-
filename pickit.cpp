#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

long long maxPoints(vector<int> &v) {
    int n = v.size();
    int 
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        vector <int> v (n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << maxPoints(v) << endl;

        cin >> n;
    }
}
