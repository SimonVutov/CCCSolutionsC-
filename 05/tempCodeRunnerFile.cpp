#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<vector<int> > > v(n);

    for (int i = 0; i < n; i++) {
        int c, r;
        cin >> c >> r;

        vector<vector<int> > v1(c, vector<int>(r));
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < r; k++) {
                cin >> v1[j][k];
            }
        }

        v[i] = v1;
    }

    vector<vector<int> > A = v[0];

    for (int i = 1; i < n; i++) {
        vector<vector<int> > B = v[i];

        vector<vector<int> > created (A.size() * B.size(), vector<int>(A[0].size() * B[0].size()));

        for (int j = 0; j < A.size(); j++) { // for each y in A
            for (int k = 0; k < A.size(); k++) { // for each x in A
                for (int l = B.size() * j; l < B.size() * (j + 1); l++) { // for each y in B
                    for (int m = B[0].size() * k; m < B[0].size() * (k + 1); m++) { // for each x in B
                        created[l][m] = A[j][k] * B[l - B.size() * j][m - B[0].size() * k];
                    }
                }
            }
        }

        A = created;
    }

    int maxElement = 0;
    int minElement = 1000000000;
    int maxRow = 0;
    int minRow = 1000000000;
    int maxCol = 0;
    int minCol = 1000000000;

    for (int i = 0; i < A.size(); i++) {
        int rowSum = 0;
        for (int j = 0; j < A[0].size(); j++) {
            rowSum += A[i][j];
            maxElement = max(maxElement, A[i][j]);
            minElement = min(minElement, A[i][j]);
        }
        maxRow = max(maxRow, rowSum);
        minRow = min(minRow, rowSum);
    }

    for (int i = 0; i < A[0].size(); i++) {
        int colSum = 0;
        for (int j = 0; j < A.size(); j++) {
            colSum += A[j][i];
        }
        maxCol = max(maxCol, colSum);
        minCol = min(minCol, colSum);
    }

    cout << maxElement << endl;
    cout << minElement << endl;
    cout << maxRow << endl;
    cout << minRow << endl;
    cout << maxCol << endl;
    cout << minCol << endl;
}
