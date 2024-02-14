#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double N, Ra, Rb, K;
    cin >> N >> Ra >> Rb >> K;
    string result;
    cin >> result;
    double aRating = 0, bRating = 0;
    for (int i = 0; i < N; i++) {
        double score = 0;
        if (result[i] == 'W') {
            score = 1;
        } else if (result[i] == 'L') {
            score = 0;
        } else {
            score = 0.5;
        }

        aRating = Ra + (score  - 1/(pow(10, (Rb - Ra)/(double)400) + 1)) * K;
        bRating = Rb + ((1 - score)  - 1/(pow(10, (Ra - Rb)/(double)400) + 1)) * K;

        Ra = aRating;
        Rb = bRating;

        cout << aRating << " " << bRating << endl;
    }
}
