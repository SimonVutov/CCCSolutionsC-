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
    int n;
    cin >> n;

    vector<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0 && s.size() > 0) s.pop_back();
        else s.push_back(x);
    }

    int sum = 0;
    for (int i = 0; i < s.size(); i++) sum += s[i];
    cout << sum;
}
