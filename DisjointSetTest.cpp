#include <iostream>
#include <vector>
using namespace std;

int findParent(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> parent(N);
    for (int i = 0; i < N; ++i)
        parent[i] = i;

    vector<int> u;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        int pa = findParent(parent, a);
        int pb = findParent(parent, b);

        if (pa != pb) {
            parent[pa] = pb;
            u.push_back(i + 1);
        }
    }

    if (u.size() >= N - 1) {
        for (int i : u)
            cout << i << endl;
    } else {
        cout << "Disconnected Graph" << endl;
    }
}