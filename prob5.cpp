#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> u (N, 0);
    vector<int> v (N, 0);
    for (int i = 0; i < N; i++) {
        cin >> u[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    vector<int> a (Q, 0);
    vector<int> b (Q, 0);
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i];
    }

    
}
