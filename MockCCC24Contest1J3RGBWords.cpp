#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    string word;
    cin >> word;

    long long count = 0;

    vector<long long> redsBefore, bluesAfter;

    long long curRed = 0, curBlue = 0;

    bool hitGreen = false;

    for (int i = 0; i < N; i++) {
        if (word[i] == 'R') {
            curRed++;
        }
        if (word[i] == 'B') {
            curBlue++;
        }
        if (word[i] == 'G') {
            redsBefore.push_back(curRed);
            if (hitGreen) bluesAfter.push_back(curBlue);
            hitGreen = true;

            curRed = 0;
            curBlue = 0;
        }
    }

    bluesAfter.push_back(curBlue);

    for (int i = 0; i < (int)redsBefore.size(); i++) {
        count += redsBefore[i] * bluesAfter[i];
    }

    cout << count << endl;
}
