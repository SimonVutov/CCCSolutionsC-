#include <iostream>

using namespace std;

double solve() {
    double totalMoney = 0;
    double timesPlayed = 0;

    double curCount = 1;

    for (int i = 0; i < 1000000; i++) {
        //50 50 chance
        if (rand() % 2 == 0) {
            curCount++;
        } else {
            totalMoney += pow(2, curCount);
            curCount = 1;
            timesPlayed++;
        }
    }

    return totalMoney / timesPlayed;
}

int main() {
    double total = 0;
    double times = 0;
    for (int i = 0; i < 100000000; i++) {
        double thisTime = solve();
        total += thisTime;
        times++;
        cout << total / times << endl;
    }
}
