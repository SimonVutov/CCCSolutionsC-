#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

string subtractStrings(const string& a, const string& b) {
    string result;

    int carry = 0;
    int n = a.size();
    int m = b.size();

    for (int i = n - 1, j = m - 1; i >= 0 || j >= 0 || carry; i--, j--) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;
        int digitB = (j >= 0) ? b[j] - '0' : 0;

        int tempResult = digitA - digitB - carry;
        if (tempResult < 0) {
            tempResult += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result = to_string(tempResult) + result;
    }

    size_t nonZeroPos = result.find_first_not_of('0');
    result = (nonZeroPos != string::npos) ? result.substr(nonZeroPos) : "0";

    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        string start = x;
        while (x.length() > 2) {
            cout << x << endl;
            x = subtractStrings(x.substr(0, x.length() - 1), x.substr(x.length() - 1, 1));
        }
        cout << x << endl;
        if (stoi(x) % 11 == 0) cout << "The number " << start << " is divisible by 11." << endl;
        else cout << "The number " << start << " is not divisible by 11." << endl;
        if (i != n - 1) cout << endl;
    }
}
