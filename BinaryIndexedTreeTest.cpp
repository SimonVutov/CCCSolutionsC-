#include <iostream>
#include <vector>
using namespace std;

class BinaryIndexedTree {
public:
    BinaryIndexedTree(int size) {
        tree.resize(size + 1, 0);
    }

    void update(int index, long long value) {
        while (index < (int)tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }

    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

private:
    vector<long long> tree;
};

int main() {
    int N, M;
    cin >> N >> M;

    BinaryIndexedTree bit(100001);
    BinaryIndexedTree bit2(100001);
    vector<int> array(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> array[i];
        bit.update(i, array[i]);
        bit2.update(array[i], 1);
    }

    for (int i = 0; i < M; ++i) {
        char op;
        cin >> op;

        if (op == 'C') {
            int index;
            long long value;
            cin >> index >> value;
            bit.update(index, value - array[index]);

            bit2.update(array[index], -1);
            bit2.update(value, 1);

            array[index] = value;
        } else if (op == 'S') {
            int left, right;
            cin >> left >> right;
            cout << bit.query(right) - bit.query(left - 1) << endl;
        } else if (op == 'Q') {
            int value;
            cin >> value;
            cout << bit2.query(value) << endl;
        }
    }

    return 0;
}
