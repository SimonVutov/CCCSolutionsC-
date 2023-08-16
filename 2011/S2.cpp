#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int N = 0;
    cin >> N;
    vector<string> a;
    vector<string> b;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        b.push_back(s);
    }

    int t = 0;

    for (int i = 0; i < N; i++) {
        if (a[i] == b[i]) t++;
    }

    cout << t << endl;
}