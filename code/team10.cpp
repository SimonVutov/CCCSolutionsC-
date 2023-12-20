#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string final;
    cin >> final;

    unordered_map<string, vector<string> > m;
    unordered_set<string> all;
    for (int i = 0; i < n; i++) {
        string from, to;
        cin >> from >> to;
        m[from].push_back(to);
        all.insert(from);
    }

    int amountReachingFinal = 0;

    for (auto i : all) {
        if (i == final) {
            continue;
        }
        //dfs, looking to reach final
        stack<string> s;
        s.push(i);
        unordered_set<string> visited;
        while (!s.empty()) {
            string temp = s.top();
            s.pop();
            if (visited.find(temp) != visited.end()) continue;
            visited.insert(temp);
            if (temp == final) {
                amountReachingFinal++;
                break;
            }
            for (auto j : m[temp]) {
                s.push(j);
            }
        }
    }

    cout << amountReachingFinal << endl;
}