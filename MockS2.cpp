#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int lastID = n - 1;

    vector<int> v (n);
    int placing = n;
    for (int i = n - 1; i > n - k; i--) {
        v[i] = placing;
        placing--;
        lastID = i - 1;
    }

    if (placing == 0) {
        //cout vector
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        return 0;
    }

    v[0] = placing;
    placing--;

    if (placing == 0) {
        //cout vector
        for (int i = 0; i < n; i++)  {
            cout << v[i] << " ";
        }
        return 0;
    }

    for (int i = lastID; i >= 0; i--) {
        if (placing == 0) {
            //cout vector
            for (int i = 0; i < n; i++)  {
                cout << v[i] << " ";
            }
            return 0;
        }
        v[i] = placing;
        placing--;
    }
}