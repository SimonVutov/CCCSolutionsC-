#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int len, r;
    cin >> len >> r;
    vector<int> s (r), e (r), gdc (r);
    for (int i = 0; i < r; i++) {
        cin >> s[i] >> e[i] >> gdc[i];
    }

    vector<int> ans (len);
}