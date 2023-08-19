#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int step (int n) {
    if (n == 1) return 0;
    int largestFactorOfN = 0;
    for (int i = 1; i < n; i++) if (n % i == 0) largestFactorOfN = i;
    
    for (int i = largestFactorOfN; i >0; i--) {
        if ((n-i) % i == 0)
            return ((n-i) / i) + step(n-i);
    }

    return 0;
}

int main () {
    int t = 0;
    cin >> t;

    cout << step(t) << endl;
}