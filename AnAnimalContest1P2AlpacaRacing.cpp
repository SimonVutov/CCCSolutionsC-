#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    long long N, D, K, X, P;
    cin >> N >> D >> K >> X;
    vector<double> v (N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
    cin >> P;

    for (int i = 0; i < N; i++) {
        while (v[i] >= P) {
            v[i] = floor(static_cast<double>((100 - X) * v[i]) / 100.0);
            K--;
        }
        if (K < 0) break;
    }

    cout << (K >= 0 ? "YES" : "NO");
}