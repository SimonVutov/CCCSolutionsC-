#include <iostream>
#include <vector>
using namespace std;

int knapsack(int budget, const vector<int>& c, const vector<int>& v, vector<int>& t, int N) {
    vector<vector<int> > DP(N + 1, vector<int>(budget + 1, 0)); // Initialize the vector with zeros

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= budget; j++) {
            DP[i][j] = DP[i - 1][j];
            if (j >= c[i - 1] && DP[i][j - c[i - 1]] + v[i - 1] > DP[i][j])
                DP[i][j] = DP[i][j - c[i - 1]] + v[i - 1];
        }
    }

    return DP[N][budget];
}

int main() {
    int types, partsCount;
    cin >> types >> partsCount;

    vector<int> cost(partsCount), valu(partsCount), type(partsCount);

    for (int i = 0; i < partsCount; i++)
        cin >> cost[i] >> valu[i] >> type[i];
    
    int budget;
    cin >> budget;

    cout << knapsack(budget, cost, valu, type, partsCount) << endl;
}
