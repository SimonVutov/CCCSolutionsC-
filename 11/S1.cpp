#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int N = 0;
    cin >> N;
    cin.ignore();
    int scount = 0;
    int tcount = 0;
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < (int)s.length(); j++) {
            if (s[j] == 's' || s[j] == 'S') {
                scount++;
            } else if (s[j] == 't' || s[j] == 'T') {
                tcount++;
            }
        }
    }

    if (tcount > scount) cout << "English" << endl;
    else cout << "French" << endl;
}