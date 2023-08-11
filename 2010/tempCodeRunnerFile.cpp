#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int numberInSequence, v;
    while (true) {
        cin >> numberInSequence;
        if (numberInSequence == 0) break;

        if (numberInSequence == 1) {
            cout << 0 << endl;
            continue;
        }

        vector <int> current; vector <int> difference;

        for (int i = 0; i < numberInSequence; i++) {
            cin >> v;
            current.push_back(v);
        }

        for (int i = 0; i < numberInSequence - 1; i++) {
            difference.push_back(current[i + 1] - current[i]);
        }

        int difSize = difference.size();

        for (int i = 1; i < difSize; i++) {
            int current = 0; bool works = true;
            for (int j = 0; j < difSize; j++) {
                if (difference[j] != difference[current]) {
                    works = false;
                    break;
                }
                current++;
                current = current % i;
            }
            if (works) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
