#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second) < (b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int planets, s;
    cin >> planets >> s;
    s--;

    vector<pair<int, int> > go (planets, make_pair(0, 0)); //get, use
    for (int i = 0; i < planets; i++) cin >> go[i].first >> go[i].second;
    int first1 = go[s].first;
    int first2 = go[s].second;
    sort(go.begin(), go.end(), customComparator);
    for (int i = 0; i < planets; i++) if (go[i].first == first1 && go[i].second == first2) s = i;

    vector<int> dif (planets, 0);
    for (int i = 0; i < planets; i++) dif[i] = go[i].first - go[i].second;

    vector<bool> visited (planets, false);
    visited[s] = true;
    int count = 1;
    int fuel = go[s].first;

    int at = -1;

    while (at < planets - 1) {
        at++;

        if (visited[at]) continue;
        if (dif[at] < 0) continue;
        if (fuel < go[at].second) continue;

        visited[at] = true;
        count++;
        fuel += dif[at];
    }

    cout << fuel << "\n" << count << "\n";
}
