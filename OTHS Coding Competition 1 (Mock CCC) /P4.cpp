#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, S, T;
    cin >> N >> S >> T;
    vector<int> sum(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    int ans = 0;

    for (int i = 0; i <= T; i++) {
        // i used on left side
        if (i * S <= N && (T - i) * S <= N) {
            int leftSum = sum[i * S];
            int rightSum = sum[N] - sum[N - (T - i) * S];
            ans = max(ans, leftSum + rightSum);
        }
    }

    if (S * T > N) {
        cout << sum[N];
        return 0;
    }

    cout << min(sum[N], ans);
    return 0;
}
