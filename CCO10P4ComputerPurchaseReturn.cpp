#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;

struct Computer {
    int c, v, t;//cost, value, type
    Computer(int c, int v, int t) : c(c), v(v), t(t) {}
};

//compare by type
bool compare(Computer a, Computer b) {
    return a.t < b.t;
}

int main() {
    int types, computers, budget;
    cin >> types >> computers;
    vector<Computer> comp;

    for (int i = 0; i < computers; i++) {
        int c, v, t;
        cin >> c >> v >> t;
        comp.push_back(Computer(c, v, t));
    }
    cin >> budget;

    //sort by type
    sort(comp.begin(), comp.end(), compare);

    //0/1 knapsack, but you can't inlude 2 of the same type
    vector<vector<int> > dp(computers + 1, vector<int>(budget + 1, 0));
    int lastOfDiffType = 0;
    for (int i = 1; i <= computers; i++) {
        for (int j = 1; j <= budget; j++) {
            // set last of diff type to i-1 if the type is different
            if (comp[i - 1].t != comp[lastOfDiffType].t) {
                lastOfDiffType = i - 1;
            }

            dp[i][j] = dp[i - 1][j];
            if (j >= comp[lastOfDiffType].c) {
                dp[i][j] = max(dp[i][j], dp[lastOfDiffType][j - comp[lastOfDiffType].c] + comp[i].v);
            }
        }
    }

    cout << dp[computers][budget] << endl;

    return 0;
}