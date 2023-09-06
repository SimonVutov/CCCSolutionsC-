#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findGroup(int person, vector<int>& fGIX) {
    while (fGIX[person] != person) {
        fGIX[person] = fGIX[fGIX[person]];
        person = fGIX[person];
    }
    return person;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    
    vector<int> arr;
    vector<long long> fG_first;
    vector<long long> fG_second;
    vector<int> fGIX;

    arr.reserve(n + 5);
    fG_first.resize(n + 5);
    fG_second.resize(n + 5);
    fGIX.resize(n + 5);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fG_first[i] = 1LL;
        fG_second[i] = x;
        fGIX[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, b;
            cin >> a >> b;
            int x = min(a, b), y = max(a, b);
            x--; y--;

            int fx = findGroup(x, fGIX);
            int fy = findGroup(y, fGIX);
            
            if (fx != fy) {
                fG_first[fx] += fG_first[fy];
                fG_second[fx] += fG_second[fy];
                fG_first[fy] = -1LL;
                fG_second[fy] = fx;

                fGIX[fy] = fx;
            }
        } else {
            int a;
            cin >> a;
            a--;

            int fa = findGroup(a, fGIX);
            cout << (t == 2 ? fG_first[fa] : fG_second[fa]) << '\n';
        }
    }

    return 0;
}
