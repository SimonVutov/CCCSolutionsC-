#include <iostream>
#include <vector>
using namespace std;

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m, 0);

    int length = 0;
    int i = 1;
    lps[0] = 0;

    while (i < (int)pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    i = 0;  // Index for text[]
    int j = 0;  // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            cout << i-j << endl;
            return 0;
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}