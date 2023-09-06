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

    void change(int index, long long value) {
        update(index, value - query(index) + query(index - 1));
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
        array[i]++;
        bit.update(i, array[i]);
        bit2.update(array[i], 1);
    }

    for (int i = 0; i < M; ++i) {
        string op;
        cin >> op;

        if (op == "U") {
            int index;
            long long value;
            cin >> index >> value;
            value++;
            bit.change(index, value);

            bit2.update(array[index], -1);
            bit2.update(value, 1);

            array[index] = value;
        } else if (op == "Q1") {
            int left, right;
            cin >> left >> right;
            cout << bit.query(right) - bit.query(left - 1) - (right - left + 1) << endl;
        } else if (op == "Q2") {
            int value1, value2;
            cin >> value1 >> value2;
            value1++; value2++;
            cout << bit2.query(value2) - bit2.query(value1 - 1) << endl;
        }
    }

    return 0;
}
