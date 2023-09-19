#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//ECOO 2016 R2 P1 - Palindrome Panic

int main() {
    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        int ans = 0;
        int change = 1;
        for (int i = s.length()/2; i > 0 && i < s.length(); i+=0) {
            int l = i, r = i;
            while (l >= 0 && r < (int)s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            ans = max(ans, i - l + 1);
            l = i, r = i + 1;
            while (l >= 0 && r < (int)s.length() && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r == (int)s.length() - 1 || l == 0)ans = max(ans, i - l + 1);

            if (change % 2) i += change;
            else i -= change;
            change++;
        }
        cout << s.length() - ans << endl;
    }
}
