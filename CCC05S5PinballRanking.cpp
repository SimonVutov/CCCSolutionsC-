#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

struct Node {
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

void insrt(Node* root, int val) {
    if (val < root->val) {
        if (root->left == nullptr) {
            root->left = new Node();
            root->left->val = val;
        } else {
            insrt(root->left, val);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new Node();
            root->right->val = val;
        } else {
            insrt(root->right, val);
        }
    }
}

int main() {
    int t;
    cin >> t;
    int sum = 0;
    vector<int> v;
    for (int i = 0; i < t; i++) {
        int cur;
        cin >> cur;

        int at = 0;
        while (at < (int)v.size() && v[at] > cur) at++;
        v.insert(v.begin() + at, cur);

        sum += at + 1;
    }

    cout << (double)sum/t << endl;
}