#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_map>
using namespace std;

int main () {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        int v[l], v2[l];

        for (int j = 0; j < l; j++) cin >> v[j];
        for (int j = 0; j < l; j++) cin >> v2[j];

        unordered_map<int, int> index_map;
        for (int j = 0; j < l; j++) index_map[v2[j]] = j;

        int largest = 0;
        for (int j = 0; j < l; j++) {
            if (index_map.find(v[j]) != index_map.end()) {
                largest = max(largest, index_map[v[j]] - j);
            }
        }

        cout << "The maximum distance is " << largest << endl;
    }
}