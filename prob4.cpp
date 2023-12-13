#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int> > v(n, vector<int>(n, -1));

    long long t = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a - 1][b - 1] = c;
        v[b - 1][a - 1] = c;
        t += c;
    }

    cout << t << endl;

    return 0;
}
