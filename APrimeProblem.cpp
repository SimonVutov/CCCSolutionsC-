#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

int aproximate(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (i % 2 == 0) continue;
        bool isPrime = true;
        for (int j = 3; j <= sqrt(i); j += 2) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) count++;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    bitset<10000001> primes;
    primes.set();
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= 10000000; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= 10000000; j += i) {
                primes[j] = 0;
            }
        }
    }
    // Make sum array
    vector<int> sum(10000001, 0);
    for (int i = 1; i < (int)sum.size(); i++) sum[i] = sum[i - 1] + primes[i];

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        if (start > 10000000 || end > 10000000) {
            cout << aproximate(start, end) << endl;
        }
        else cout << sum[end] - sum[start - 1] << endl;
    }

    return 0;
}