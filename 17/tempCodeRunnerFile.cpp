#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n = 0;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A[i] = x;
    }

    sort(A, A + n);

    for (int i = 0; i < n/2; i++)
        cout << A[n/2 - i - 1] << " " << A[n/2 + i] << " ";

    if (n % 2) cout << A[n-1];
}