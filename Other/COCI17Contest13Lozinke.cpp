#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std; //not work

int main () {
    int n;
    cin >> n;
    vector<vector<int> > v (n, vector<int> (26, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) v[i][s[j] - 'a']++;
    }

    int t = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool good = true;
            for (int k = 0; k < 26; k++) {
                if (v[i][k] > v[j][k]) {
                    good = false;
                    break;
                }
            }
            if (good) t++;
        }
    }

    cout << t << endl;
}