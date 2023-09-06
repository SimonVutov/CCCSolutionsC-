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
    vector<vector<vector<long long> > > v(n);

    for (int i = 0; i < n; i++) {
        int c, r;
        cin >> c >> r;

        vector<vector<long long> > v1(c, vector<long long>(r));
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < r; k++) {
                cin >> v1[j][k];
            }
        }

        v[i] = v1;
    }

    vector<vector<long long> > A = v[0];

    for (int i = 1; i < n; i++) {
        vector<vector<long long> > B = v[i];

        vector<vector<long long> > created (A.size() * B.size(), vector<long long>(A[0].size() * B[0].size()));

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

    long long maxElement = 0;
    long long minElement = 1000000000000000000;
    long long maxRow = 0;
    long long minRow = 1000000000000000000;
    long long maxCol = 0;
    long long minCol = 1000000000000000000;

    for (int i = 0; i < A.size(); i++) {
        long long rowSum = 0;
        for (int j = 0; j < A[0].size(); j++) {
            rowSum += A[i][j];
            maxElement = max(maxElement, A[i][j]);
            minElement = min(minElement, A[i][j]);
        }
        maxRow = max(maxRow, rowSum);
        minRow = min(minRow, rowSum);
    }

    for (int i = 0; i < A[0].size(); i++) {
        long long colSum = 0;
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
