#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

//Manacher's Algorithm problem
//https://dmoj.ca/problem/cco97p1

int main () {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        string str = "#";
        for (size_t i = 0; i < s.length(); i++) {
            str += s[i];
            str += '#';
        }

        vector<int> P (str.length(), 0);
        int C = 0; //center
        int R = 0; //rightmost palindrome

        for (int j = 0; j < (int)str.length(); j++) {
            int mirror = 2 * C - j; //value of j mirrored over center c
            
            if (j < R) P[j] = min(R - j, P[mirror]);

            int a = j + (1 + P[j]);
            int b = j - (1 + P[j]);

            while (a < (int)str.length() && b >= 0 && str[a] == str[b]) { // Expand while characters match and are within bounds
                P[j]++; a++; b--;
            }

            if (j + P[j] > R) { // Update the rightmost palindrome if necessary
                C = j;
                R = j + P[j];
            }
        }

        int maxLen = 0; // Finding the Longest Palindromic Substring
        int centerIndex = 0;

        for (int j = 0; j < (int)str.length(); j++) {
            if (P[j] > maxLen) {
                maxLen = P[j];
                centerIndex = j;
            }
        }

        string longestPalindrome = s.substr(centerIndex/2 - maxLen/2, 2 * maxLen/2);

        cout << longestPalindrome << "\n";

        cout << longestPalindrome.length() << "\n";
    }
}