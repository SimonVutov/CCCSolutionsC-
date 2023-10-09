#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;

int main() {
    int N, H, P;
    cin >> N >> H >> P;
    vector<int> bosses(N);
    for (int i = 0; i < N; i++) {
        cin >> bosses[i];
    }

    sort(bosses.begin(), bosses.end());

    cout << ((bosses[N - 1] - bosses[N - 2]) * min(P, H) + bosses[N - 2] * H) << endl;
}
