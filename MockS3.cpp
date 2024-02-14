#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v (n);
    int leftC = 0, rightC = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        rightC += v[i];
    }

    int optDist = 1000000000, optID = -1, optSwap = -1;

    for (int i = 0; i < n; i++) {
        rightC -= v[i];

        // loop
        int dif = abs(leftC - rightC);
        int low = 0, high = n - 1;
        if  (leftC < rightC) low = i + 1;
        else high = i - 1;

        if (dif == 0) {
            cout << i + 1 << " " << -1 << endl;
            return 0;
        }

        for (int j = low; j <= high; j++) {
            int newDif = abs(dif - 2 * v[j]);
            if (newDif < optDist) {
                optDist = newDif;
                optID = i;
                optSwap = j;
            }
        }

        leftC += v[i];
    }

    cout << optID + 1 << " " << optSwap + 1 << endl;
}