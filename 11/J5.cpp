#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Node {
    int value;
    vector<Node*> c;

    Node(int v) { value = v; c = vector<Node*>();}
};

double num(Node* node) {
    if (node->c.size() == 0) return 1;
    int t = 0;
    int k = pow(2, node->c.size());
    //cout << " k of " << node->value << " is " << k << endl;
    for (int i = 0; i < (int)node->c.size(); i++) {
        t += (num(node->c[i]) - 1) * (k / 2);
    }
    //cout << " t of " << node->value << " is " << t << endl;
    t += k;
    return t;
}

int main () {
    int n;
    cin >> n;

    int a[n-1];
    for (int i = 0; i < n-1; i++) cin >> a[i];

    Node* root = new Node(n);
    vector<Node*> tips = vector<Node*>();
    tips.push_back(root);

    for (int i = n - 1; i > 0; i--) {
        Node* node = new Node(i);
        int valLookingFor = a[i-1];

        for (int j = 0; j < (int)tips.size(); j++) {
            if (tips[j]->value == valLookingFor) {
                tips[j]->c.push_back(node);
                tips.push_back(node);
                break;
            }
        }
    }

    double sumOfPossibleSets = num(root);

    cout << fixed << setprecision(0) << sumOfPossibleSets << endl;
}