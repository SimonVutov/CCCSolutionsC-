#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long log2_(long long n) {
    long long ans = 0;
    while (n > 1) {
        n /= 2;
        ans++;
    }
    return ans;
}

int main() {
    long long N, T;
    cin >> N >> T;
    string s;
    cin >> s;
    while (T > 0) {
        long long k = pow(2, (int)log2_(T));
        string temp = s;
        for (int i = 0; i < N; i++) {
            temp[i] = (s[(N + i - (k%N)) % N] == s[(N + i + (k%N)) % N]) ? '0' : '1';
        }
        s = temp;
        T -= k;
    }

    cout << s << endl;
}
