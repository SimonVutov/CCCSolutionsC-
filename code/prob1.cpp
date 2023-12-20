#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    unordered_map<string, int> m1, m2;


    for (int i = 0; i < a; i++) {
        string s;
        cin >> s;
        m1[s]++;
    }
    for (int i = 0; i < b; i++) {
        string s;
        cin >> s;
        m2[s]++;
    }

    int x = 0, y = 0;

    for (auto i : m1) {
        //x += i / 2;
        x += i.second / 2;
    }

    for (auto i : m2) {
        //y += i / 2;
        y += i.second / 2;
    }

    if (y > x) {
        cout << "Bob wins with " << y << " pairs" << endl;
    }
    else if (x > y) {
        cout << "Alice wins with " << x << " pairs" << endl;
    }
    else {
        cout << "Tie" << endl;
    }
}
