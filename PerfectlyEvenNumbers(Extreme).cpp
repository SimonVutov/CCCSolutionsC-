#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    string input;
    cin >> input;

    long long ans = 0;

    for (int i = 0; i < (int)input.length(); i++) {
        long long exp = input.length() - i - 1;
        long long digit = input[i] - '0';

        long long pow5 = 1;
        for (int j = 0; j < exp; j++) {
            pow5 *= 5;
            pow5 %= 1000000007;  // Apply modulo here to avoid overflow
        }

        ans = (ans + digit * (pow5 - 1)) % 1000000007;  // Apply modulo here
    }

    cout << ans << endl;

    return 0;
}
