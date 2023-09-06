#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n, make_pair(-1, -1)); // a freinds to b
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    int a, b;
    cin >> a >> b;
    while (a != 0 && b != 0) {
        int seperation = -1;
        bool found = false;
        int at = a;
        while (true) {
            for (int i = 0; i < n; i++) {
                if (v[i].first == at) {
                    seperation++;
                    at = v[i].second;
                    break;
                }
            }
            if (at == b) {
                found = true;
                break;
            } else if (at == a) {
                break;
            }
        }

        if (found) {
            cout << "Yes " << seperation << endl;
        } else {
            cout << "No" << endl;
        }

        cin >> a >> b;
    }
}
