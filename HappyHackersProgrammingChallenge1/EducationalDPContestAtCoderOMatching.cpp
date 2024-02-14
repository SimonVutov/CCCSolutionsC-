#include <iostream>

using namespace std;

int countM (vector<vector<int> > a, int i) {
    int n = a.size();
    if (i == n) {
        return 1; //end of one match
    }

    cout << "i: " << i << endl;

    int total = 0;

    for (int j = 0; j < n; j++) {
        if (a[i][j] == 0) continue;
        a[i][j] = 0; //remove the match
        total += countM(a, i + 1);
        a[i][j] = 1; //put the match back
    }

    return total;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > a (n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; i < n; j++) {
            cout << "i: " << i << " j: " << j << endl;
            cin >> a[i][j];
        }
    }

    cout << countM(a, 0) << endl;
}
