#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, k;
    cin >> N >> k;
    vector<int> marbles (N);
    string input;
    cin >> input;
    for (int i = 0; i < N; i++) {
        if (input[i] == '1') {
            marbles[i] = 1;
        } else {
            marbles[i] = 0;
        }
    }

    //initial binding
    for (int i = 0; i < N - 1; i++) {
        if (marbles[i + 1] == 1) {
            marbles[i] = 0;
        }
    }

    int cur = 0;
    bool hitone = false;

    vector<int> spacings;
    int totalMarbles = 0;

    for (int i = 0; i < N; i++) {
        if (marbles[i] == 1) {
            totalMarbles++;
            if (hitone) {
                spacings.push_back(cur);
            }
            hitone = true;
            cur = 0;
        } else {
            cur++;
        }
    }

    sort(spacings.begin(), spacings.end());

    int at = 0;
    int size = spacings.size();
    while (at < size && k - spacings[at] >= 0) {
        totalMarbles--;
        k -= spacings[at];
        at++;
    }

    if (k > 0) {
        totalMarbles++;
    }

    cout << totalMarbles << endl;
}
