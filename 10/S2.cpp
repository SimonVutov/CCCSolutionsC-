#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Node {
public:
    string data;
    Node* left;
    Node* right;
    Node(string val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int main () {
    int n;
    cin >> n;
    Node* root = new Node("-");

    for (int i = 0; i < n; i++) {
        string s; string path;
        cin >> s >> path;

        Node* curr = root;
        for (int j = 0; j < (int)path.length(); j++) {
            string insert = "-";
            if (j == ((int)path.length() - 1)) insert = s;

            if (path[j] == '0') {
                if (curr->left == NULL) curr->left = new Node(insert);
                curr = curr->left;
            } else {
                if (curr->right == NULL) curr->right = new Node(insert);
                curr = curr->right;
            }
        }
    }

    string sequence = "";
    cin >> sequence;

    Node* curr = root;
    string ans = "";
    for (int i = 0; i < (int)sequence.length(); i++) {
        if (sequence[i] == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        if (curr->data != "-") {
            ans += curr->data;
            curr = root;
        }
    }

    cout << ans << endl;
}