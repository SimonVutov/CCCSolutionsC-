#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
    int p, n;
    cin >> p >> n;

    vector<int> ps (p, -1);
    for (int i = 0; i < p; i++) {
        int x;
        cin >> x;
        x--;
        while (x > 0 && ps[x] != -1) x--;
        if (ps[x] == -1) ps[x] = 1;
        else { cout << i; return 0; }
    }

    cout << p;
}
