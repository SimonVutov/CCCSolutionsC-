#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c, pr, pc, kr, kc;
        cin >> r >> c >> pr >> pc >> kr >> kc;
        pr--;
        pc--;
        kr--;
        kc--;

        int pmap[r][c];
        int kmap[r][c];
        for (int j = 0; j < r; j++) for (int k = 0; k < c; k++) {
            pmap[j][k] = -10;
            kmap[j][k] = -10;
        }

        int at = pr;
        int max = 0;
        pmap[pr][pc] = 0;
        while (at < r) {
            at++;
            pmap[at][pc] = pmap[at-1][pc] + 1;
            max = pmap[at-1][pc];
        }

        queue<pair<int, int> > q; // r, c
        kmap[kr][kc] = 0;
        q.push(make_pair(kr, kc));
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            int cr = cur.first, cc = cur.second;
            int moves[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

            for (int j = 0; j < 8; j++) {
                int nr = cr + moves[j][0], nc = cc + moves[j][1];
                if (nr < 0 || nc < 0 || nr >= r || nc >= c) continue;
                if (kmap[nr][nc] != -10) continue;
                kmap[nr][nc] = kmap[cr][cc] + 1;
                q.push(make_pair(nr, nc));
            }
        }
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                if (kmap[j][k] == pmap[j][k]) {
                    cout << "Win in " << kmap[j][k] << " knight move(s)." << endl;
                    goto outer;
                }
                else if (kmap[j][k] == pmap[j][k] + 1) {
                    cout << "Stalemate in " << kmap[j][k] << " knight move(s)." << endl;
                    goto outer;
                }
            }
        }
        cout << "Loss in " << max - 1 << " knight move(s)." << endl;
        outer:;
    }
}