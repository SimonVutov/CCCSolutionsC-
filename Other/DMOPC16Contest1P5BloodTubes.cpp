#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> blood(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> blood[i];
        blood[i]--;
    }

    vector<int> table(n, 0);

    int inversions = 0;

    for (int i = 0; i < n; i++) {
        table[blood[i]] = 1;
        int r = 0;
        for (int j = blood[i] + 1; j < n; j++) r += table[j];
        int l = 0;
        for (int j = 0; j < blood[i]; j++) l += table[j];
        inversions += min(l, r);
    }

    cout << inversions << endl;
}