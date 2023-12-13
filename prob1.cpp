#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    p--;
    vector<vector<int> > v(n, vector<int>(n, 0));
    int counter = 1;
    int peakSeen = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && peakSeen < p) {
                peakSeen++;
                continue;
            }
            v[i][j] = counter;
            counter++;
        }
    }
    for (int i = 0; i < p; i++) {
        v[i][i] = counter;
        counter++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}