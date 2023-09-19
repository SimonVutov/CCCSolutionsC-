#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std; //doesnt work for some reason???

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> v(l);
        for (int j = 0; j < l; j++) {
            cin >> v[j];
        }
        vector<int> v2(l);
        for (int j = 0; j < l; j++) {
            cin >> v2[j];
        }

        vector<int> v2FirstOccurance (1000001, -1);
        vector<int> v2LastOccurance (1000001, -1);
        for (int j = 0; j < l; j++) {
            if (v2FirstOccurance[v2[j]] == -1) {
                v2FirstOccurance[v2[j]] = j;
            }
            v2LastOccurance[v2[j]] = j;
        }

        int largest = -1;
        for (int j = 0; j < l; j++) {
            if (v2FirstOccurance[v[j]] != -1) {
                largest = max(largest, j - v2FirstOccurance[v[j]]);
                largest = max(largest, v2LastOccurance[v[j]] - j);
            }
        }

        if (largest == -1)cout << "The maximum distance is 0" << endl;
        else cout << "The maximum distance is " << largest << endl;
    }
}