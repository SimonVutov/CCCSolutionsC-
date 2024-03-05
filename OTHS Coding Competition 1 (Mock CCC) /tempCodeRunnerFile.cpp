#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> v (N);
    for (int i=0; i<N; i++) cin >> v[i];
    int bombs = 1, longest = 1, curlen = 0;
    for (int i = 1; i < N; i++) {
        curlen++;
        if (abs(v[i] - v[i-1]) > D) {
            bombs++;
            
            longest = max(longest, curlen);
            curlen = 0;
        }
    }
    longest = max(longest, curlen + 1);

    cout << bombs << endl << longest;
}