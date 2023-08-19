#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n = 0;
    cin >> n;

    int A[4023];
    for (int i = 0; i < 4023; i++) A[i] = 0;

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A[x]++;
    }

    int max = 0;
    int ways = 0;
    for (int i = 2; i <= 4000; i++) { //chose a height
        int len = 0;
        for (int j = 1; j <= i/2; j++) { //chose a width
            if (j == i - j) len += A[j] / 2;
            else len += min(A[j], A[i - j]);
        }

        if (len > max) {
            max = len;
            ways = 1;  // Reset the count of ways
        } else if (len == max) {
            ways++;  // Increment the count of ways
        }
    }

    cout << max << " " << ways << endl;
}