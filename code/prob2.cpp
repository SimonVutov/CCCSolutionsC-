#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>

using namespace std;

bool check (vector<string>& v, char player) {
    for (int i = 0; i < 3; i++) {
        if (v[i][0] == player && v[i][1] == player && v[i][2] == player) {
            return true;
        }
        if (v[0][i] == player && v[1][i] == player && v[2][i] == player) {
            return true;
        }
    }

    if (v[0][0] == player && v[1][1] == player && v[2][2] == player) {
        return true;
    }
    if (v[0][2] == player && v[1][1] == player && v[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> ans;

    for (int i = 0; i < n; i++) {
        vector<string> v;
        for (int j = 0; j < 3; j++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        string move;
        cin >> move;
        string temp;
        cin >> temp;
        cin >> temp;

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++){
                if (v[j][k] == '.') {
                    v[j][k] = move[0];
                    if (check(v, move[0])) {
                        //cout << move[0] << " can win" << endl;
                        if (move[0] == 'x') {
                            ans.push_back("x can win");
                        }
                        else {
                            ans.push_back("o can win");
                        }
                        goto outerloop;
                    }
                    v[j][k] = '.';
                }
            }
        }

        //cout << "no winning move" << endl;
        ans.push_back("no winning move");
        outerloop:
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
