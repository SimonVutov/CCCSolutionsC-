#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int longest = 0;
        int longestIX = 0;
        int evenOdd = 1;
        int amount = 1;

        int j = s.length() / 2;
        int change = -1;
        
        while (j >= 0 && j < s.length()) { //at each char
            int l = j - 1, r = j + 1, length = 0;
            while (l >= 0 && r < s.length() && (s[l] == s[r])) {
                length++;
                l--; r++;
            }
            if (length > longest) {
                longest = length;
                longestIX = j;
                evenOdd = 1;
                if (j - longest <= 1 || j + longest >= s.length() - 1) goto outerloop;
            }

            l = j - 1, r = j, length = 0;
            while (l >= 0 && r < s.length() && (s[l] == s[r])) {
                length++;
                l--; r++;
            }
            if (length > longest) {
                longest = length;
                longestIX = j;
                evenOdd = 0;
                goto outerloop;
                if (j - longest <= 1 || j + longest >= s.length() - 1) goto outerloop;
            }

            j += change * amount;
            change *= -1;
            amount++;
        }

        outerloop:

        string palindrom = s.substr(longestIX - longest, longest * 2 + evenOdd);

        cout << palindrom << "\n";
        cout << palindrom.length() << "\n";
    }
}