#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct node {
    int value = -1;
    node *left = nullptr;
    node *right = nullptr;
};

int main() {
    string in;
    getline(cin, in);
    int x, answer = 0;
    cin >> x;

    int n = in.length();
    node *root = new node;
    stack<node *> s;
    node *curr = root;

    for (int i = 0; i < n; i++) {
        if (in[i] == ' ') continue;
        if (in[i] == '(') {
            // if left is null, set left, else set right
            if (curr->left == nullptr) {
                curr->left = new node;
                s.push(curr);
                curr = curr->left;
            } else {
                curr->right = new node;
                s.push(curr);
                curr = curr->right;
            }
        } else if (in[i] == ')') {
            // go up
            curr = s.top();
            s.pop();
        } else {
            // set number
            string number = "";
            while (in[i] != '(' && in[i] != ')' && in[i] != ' ' && i < n) {
                number += in[i];
                i++;
            }
            i--;
            curr->value = stoi(number);

            // go up
            if (!s.empty()) {
                curr = s.top();
                s.pop();
            }
        }
    }

    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *curr = q.front();
        q.pop();
        cout << curr->value << endl;
        if (curr->value != -1) {
            if (curr->value >= x) {
                answer++;
            }
        }
        if (curr->left != nullptr) {
            cout << "  left" << endl;
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            cout << "  right" << endl;
            q.push(curr->right);
        }
    }

    cout << answer << endl;
}
