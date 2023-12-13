#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double dp[2005][10000]; // pos, last travel dist
vector<pair<int, int>> points;

double d(int i, int j) {
    return sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
}

int maxVisits(double pos, double lastDist) {
    if (dp[(int)pos][lastDist] != 0) return dp[pos][lastDist];
    
    for (int i = 0; i < points.size(); i++) {
        if (i == pos) continue;
        if (d(pos, i) < lastDist) {
            dp[pos][lastDist] = max(dp[pos][lastDist], maxVisits(i, lastDist - (int)d(pos, i)) + 1);
        }
    }
}

int main() {
    int N = 0;
    cin >> N;
    points.resize(N+1, make_pair(0, 0));
    points[0] = make_pair(0, 0);
    for (int i = 0; i < N; i++) {
        cin >> points[i+1].first >> points[i+1].second;
    }

    cout << maxVisits(0, (int)1e5) << endl;
}
