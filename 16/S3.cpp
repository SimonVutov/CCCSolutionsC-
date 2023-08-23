#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std;

vector<int> trim (int at, vector<vector<int> > adj, vector<int> pho) {
    bool removeThisNode = false;

    //base case
    if (adj[at].size() == 0) {
        if (pho[at] == 0) {
            removeThisNode = true;
            vector<int> temp;
            temp.push_back(at);
            return temp;
        }
    }

    //recursive case
    vector<int> remove (0, 0);
    bool thisIsUseless = false;
    
    if (pho[at] == 0) thisIsUseless = true;

    bool childIsUseless = true;
    for (int i = 0; i < adj[at].size(); i++) {
        vector<int> temp = trim(adj[at][i], adj, pho);
        for (int j = 0; j < temp.size(); j++) {
            remove.push_back(temp[j]);
        }

        int totalChildren = 0; //get total children of adj[at][i]
        vector<int> children;
        while (!children.empty()) {
            int c = children.back();
            children.pop_back();
            totalChildren++;
            for (int j = 0; j < adj[c].size(); j++) {
                children.push_back(adj[c][j]);
            }
        }

        if (temp.size() != totalChildren) { childIsUseless = false; cout << "children are useful"; }
    }

    if (childIsUseless && thisIsUseless) removeThisNode = true;
    cout << " node: " << at << childIsUseless << thisIsUseless << endl;
    if (removeThisNode) {
        //add node to array, all children should also be in array (maybe), return
        remove.push_back(at);
        cout << "returning: " << remove.size() << endl;
        return remove;
    }
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> pho (n, 0);
    for (int i = 0; i < p; i++) {
        int a;
        cin >> a;
        pho[a] = 1;
    }
    vector<vector<int> > adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        adj[a].push_back(b);
    }

    //print adj
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> toRemove = trim(0, adj, pho);

    //print trimmed

    for (int i = 0; i < toRemove.size(); i++) {
        cout << toRemove[i] << " ";
    }

    //find diameter of trimmed

    //diameter + 2 * branch lengths = answer
}
