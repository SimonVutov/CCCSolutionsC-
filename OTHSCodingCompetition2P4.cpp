#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;

    unordered_map<int, pair<int, int> > value_to_pos;
    int value;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> value;
            value_to_pos[value] = make_pair(i, j);
        }
    }
    for (int q = 0; q < K; q++) {
        int v, r1, c1, r2, c2;
        cin >> v >> r1 >> c1 >> r2 >> c2;
        if (value_to_pos.count(v) > 0) {
            pair<int, int> pos = value_to_pos[v];
            int vr = pos.first;
            int vc = pos.second;
            if (vr >= r1 && vr <= r2 && vc >= c1 && vc <= c2) cout << "yes\n";
            else cout << "no\n";
        } else cout << "no\n";
    }
}