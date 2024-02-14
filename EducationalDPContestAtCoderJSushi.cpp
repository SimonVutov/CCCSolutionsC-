#include <iostream>
#include <vector>

using namespace std;

int go(int a, int b, int c) {
    if (a == 0 && b == 0 && c == 0) {
        return 0;
    }
    int ans = 0;
    int t = a + b + c;
    if (a > 0) {
        ans += go(a - 1, b, c) * a / t + 1;
    }
    if (b > 0) {
        ans += go(a + 1, b - 1, c) * b / t + 1;
    }
    if (c > 0) {
        ans += go(a, b + 1, c - 1) * c / t + 1;
    }
    return ans;
}

int main() {
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        if (in == 1) {
            a++;
        } else if (in == 2) {
            b++;
        } else {
            c++;
        }
    }

    cout << go(a, b, c) << endl;
}
