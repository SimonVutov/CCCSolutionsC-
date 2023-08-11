#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int n, v;
    while (true) {
        bool hasPrinted = false;
        cin >> n;
        if (n == 0) break;

        if (n == 1) {
            cin >> v;
            cout << 0 << endl;
            continue;
        }

        vector <int> c; vector <int> difference;

        for (int i = 0; i < n; i++) {
            cin >> v;
            c.push_back(v);
        }

        for (int i = 0; i < n - 1; i++) {
            difference.push_back(c[i + 1] - c[i]);
        }

        int difSize = difference.size();

        for (int i = 1; i < difSize; i++) { //i is size of pattern, c is current index, j is testing
            int c = 0; bool works = true;
            for (int j = 0; j < difSize; j++) {
                if (difference[j] != difference[c]) {
                    works = false;
                    break;
                }
                c++;
                c = c % i;
            }
            if (works) {
                cout << i << endl;
                hasPrinted = true;
                break;
            }
        }
        if (!hasPrinted) cout << difSize << endl;
    }
    return 0;
}
