#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>

using namespace std;

bool isPrime(int x) {
    if (x == 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;

        int a = x, b = x;

        while (!isPrime(a) || !isPrime(b)) {
            a--;
            b++;
        }
        
        cout << a << " " << b << endl;
    }
}
