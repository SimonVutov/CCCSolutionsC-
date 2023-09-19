#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <unordered_map>
using namespace std;

struct pairS {
    string x;
    string y;
    string z;
};

int main() {
    unordered_map<string, int> m; // location of each person in groups

    int x;
    cin >> x;

    vector<pairS> v (x); // must be with

    for (int i = 0; i < x; i++) {
        cin >> v[i].x;
        cin >> v[i].y;
    }

    int y;
    cin >> y;

    vector<pairS> w (y); // must not be with

    for (int i = 0; i < y; i++) {
        cin >> w[i].x;
        cin >> w[i].y;
    }

    int z;
    cin >> z;

    vector<pairS> u (z); //groups

    for (int i = 0; i < z; i++) {
        cin >> u[i].x;
        cin >> u[i].y;
        cin >> u[i].z;

        m[u[i].x] = i;
        m[u[i].y] = i;
        m[u[i].z] = i;
    }

    int violations = 0;

    for (int i = 0; i < x; i++) if (m[v[i].x] != m[v[i].y]) violations++;
    for (int i = 0; i < y; i++) if (m[w[i].x] == m[w[i].y]) violations++;
    cout << violations << endl;
}