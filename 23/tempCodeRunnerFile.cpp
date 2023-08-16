#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

char ch () { return 'a' + rand() % 26; }

string stri (int n) {
    stringstream ss;
    for (int i = 0; i < n / 2; i++) ss << ch();
    if (n % 2 == 1) ss << ch(); //if odd add one more
    for (int i = n/2 - 1; i >= 0; i--) ss << ss.str()[i];
    return ss.str();
}

string stri (int n, string c) {
    if (c.length() > n / 2) {
        stringstream ss;
        for (int i = 0; i < c.length(); i++) ss << c[i];
        for (int i = n/2 - 1 - (c.length() - n/2); i >= 0 && ss.str().length() < n; i--) ss << ss.str()[i];
        return ss.str();
    } else{
        stringstream ss;
        ss << c;
        for (int i = c.length(); i < n / 2; i++) ss << ch();
        if (n % 2 == 1) ss << ch(); //if odd add one more
        for (int i = n/2 - 1; i >= 0; i--) ss << ss.str()[i];
        return ss.str();
    }
}

int main () {
    int y, x, r, c;
    cin >> y >> x >> r >> c;
    vector< vector<char> > v (y, vector<char> (x, '.'));
    vector< vector<bool> > keepAsIs (y, vector<bool> (x, false));

    if ((r == y && c != x) || (r != y && c == x)) { cout << "impossible" << endl; return 0; }
    //force there to be r horizontal palindromes and c vertical palindromes

    for (int i = 0; i < r; i++) { // horizontal --
        string s = stri(x);
        if (i < y/2) for (int j = 0; j < x; j++) {
            v[i][j] = s[j];
            keepAsIs[i][j] = true;
        }
        if (i >= y/2) for (int j = 0; j < x; j++) {
            v[i][j] = v[y - 1 - i][j];
        }
    }

    for (int i = 0; i < c; i++) { // vertical |
        stringstream ss;
        for (int j = 0; j < r; j++) ss << v[j][i];
        string s = stri(y, ss.str());
        for (int j = 0; j < y; j++) {
            v[j][i] = s[j];
            keepAsIs[j][i] = true;
        }
    }

    //set random letters in non-palindromes
    for (int j = 0; j < y; j++) {
        for (int k = 0; k < x; k++) {
            if (!keepAsIs[j][k]) v[j][k] = ch();
        }
    }

    //randomly change letters to remove extra palindromes, with 5 tries, if still bad: print impossible
    for (int i = 0; i < 50; i++) {
        //is there exactly r horizontal palindromes?
        int count = 0;
        for (int j = 0; j < y; j++) {
            string s = "";
            for (int k = 0; k < x; k++) s += v[j][k];
            bool isPal = true;
            for (int k = 0; k < s.length() / 2; k++) {
                if (s[k] != s[s.length() - 1 - k]) isPal = false;
            }
            if (isPal) count++;

            if (count > r) {
                //change a random letter in a random non-palindrome
                for (int k = 0; k < x; k++) {
                    if (!keepAsIs[j][k]) v[j][k] = ch();
                }
            }
        }
        if (count != r) continue;

        //is there exactly c vertical palindromes?
        count = 0;
        for (int j = 0; j < x; j++) {
            string s = "";
            for (int k = 0; k < y; k++) s += v[k][j];
            bool isPal = true;
            for (int k = 0; k < s.length() / 2; k++) {
                if (s[k] != s[s.length() - 1 - k]) isPal = false;
            }
            if (isPal) count++;
        }
        if (count != c) continue;

        //if i == 49 and here, print impossible
        if (i == 49) { cout << "impossible" << endl; return 0; }

        //if here, good
        break;
    }

    //print the result if possible
    for (int i = 0; i < y; i++) { for (int j = 0; j < x; j++) cout << v[i][j]; cout << endl; }
}