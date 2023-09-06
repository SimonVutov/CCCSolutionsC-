#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> P (n), W (n), D (n);

    for (int i = 0; i < n; i++) {
        long long p, w, d;
        cin >> p >> w >> d;
        P[i] = p;
        W[i] = w;
        D[i] = d;
    }

    long long c = 1000000000 / 2;
    long long change = 1000000000 / 4;
    long long sum = 0;
    long long minSum = 1000000000000000000;

    int iters = 0;
    while (iters++ < 50) {
        long long atC = 0;
        long long cPlus = 0;
        long long cMinus = 0;

        for (int i = 0; i < n; i++) {
            long long dist = max(0ll, (abs(P[i] - c) - D[i])) * W[i];
            atC += dist;
        }

        for (int i = 0; i < n; i++) {
            long long dist = max(0ll, (abs(P[i] - c + 1) - D[i])) * W[i];
            cPlus += dist;
        }

        for (int i = 0; i < n; i++) {
            long long dist = max(0ll, (abs(P[i] - c - 1) - D[i])) * W[i];
            cMinus += dist;
        }

        sum = atC;
        minSum = min(minSum, sum);

        if (cMinus > cPlus) c -= change;
        else c += change;

        change = max(change / 2, 1ll);
    }

    cout << minSum;
}
