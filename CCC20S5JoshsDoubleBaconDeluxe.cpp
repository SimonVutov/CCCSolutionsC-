#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

int solve(int n, vector<int> &a, int k) {
    if (k < 0 || k >= n) return 0;
    int nums = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[k] && i != k) {
            nums++;
        }
    }

    return (1/nums) * solve(n, a, k + 1) + solve(n, a, k - 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    cout << (1.0 - solve(n, a, n - 1)) << endl;
}