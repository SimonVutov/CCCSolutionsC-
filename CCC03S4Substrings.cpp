#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct SuffixTreeNode {
    unordered_map<char, SuffixTreeNode*> children;
};

void createSuffixTree(SuffixTreeNode* root, string s) {
    for (int i = 0; i < s.size(); i++) {
        SuffixTreeNode* current = root;
        for (int j = i; j < s.size(); j++) {
            if (current->children.find(s[j]) == current->children.end()) {
                current->children[s[j]] = new SuffixTreeNode();
            }
            current = current->children[s[j]];
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        SuffixTreeNode* root = new SuffixTreeNode();
        createSuffixTree(root, s);

        //print the tree, and count the number of leaf nodes

        int leafNodes = 0;

        vector<SuffixTreeNode*> queue;

        queue.push_back(root);

        while (queue.size() > 0) {
            SuffixTreeNode* current = queue[0];
            queue.erase(queue.begin());

            if (current->children.size() == 0) {
                leafNodes++;
            }

            for (auto it = current->children.begin(); it != current->children.end(); it++) {
                queue.push_back(it->second);
            }
        }

        cout << leafNodes + 1 << endl;
    }
}
