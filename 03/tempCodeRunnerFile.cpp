#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype> // Include this for the tolower() function

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> ans(n);

    for (int i = 0; i < n; i++) {
        vector<string> v(4); //lines
        vector<string> v2(4); //syllables
        for (int j = 0; j < 4; j++) {
            //read line
            getline(cin, v[j]);

            for (int k = v[j].length() - 1; k >= 0; k--) {
                v[j][k] = tolower(v[j][k]); // Convert character to lowercase
                if (v[j][k] == ' ') {
                    v2[j] = v[j].substr(k + 1, v[j].length() - k - 1);
                    break;
                }
                if (v[j][k] == 'a' || v[j][k] == 'e' || v[j][k] == 'i' || v[j][k] == 'o' || v[j][k] == 'u') {
                    v2[j] = v[j].substr(k, v[j].length() - k);
                    break;
                }
            }
        }

        cout << v2[0] << " " << v2[1] << " " << v2[2] << " " << v2[3] << endl;

        if (v2[0] == v2[1] && v2[1] == v2[2] && v2[2] == v2[3]) {
            ans[i] = "perfect";
        } else if (v2[0] == v2[1] && v2[2] == v2[3]) {
            ans[i] = "even";
        } else if (v2[0] == v2[2] && v2[1] == v2[3]) {
            ans[i] = "cross";
        } else if (v2[0] == v2[3] && v2[1] == v2[2]) {
            ans[i] = "shell";
        } else {
            ans[i] = "free";
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
}
