#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

unordered_map<string, string> map;
unordered_map<string, int> map2, map3;
unordered_set<string> visited;

bool solve (vector<pair<string, string> > v, int steps, string from, string to) {
    if (visited.find(from + to_string(steps)) != visited.end()) { return false; }
    if (from == to) return true;
    if (map.find(from) != map.end()) return false;
    for (int i = 0; i < (int)from.length(); i++) {
        for (int j = 0; j < (int)v.size(); j++) {
            if (i + v[j].first.length() > from.length()) continue;
            string section = from.substr(i, v[j].first.length());
            if (section == v[j].first) {
                string newString = from.substr(0, i) + v[j].second + from.substr(i + v[j].first.length());
                if (steps > 0) {
                    visited.insert(from + to_string(steps));
                    if (solve(v, steps - 1, newString, to)) {
                        map[newString] = from;
                        map2[newString] = j;
                        map3[newString] = i;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    vector<pair<string, string> > v (3, make_pair("", ""));
    for (int i = 0; i < 3; i++) cin >> v[i].first >> v[i].second;
    int steps;
    cin >> steps;
    string from, to;
    cin >> from >> to;

    solve(v, steps, from, to);
    string at = to;
    vector<string> ans;
    while (at != from) {
        ans.push_back(to_string(map2[at] + 1) + " " + to_string(map3[at] + 1) + " " + at);
        at = map[at];
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }
}