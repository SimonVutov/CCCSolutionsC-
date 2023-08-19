#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int time, chores;
    cin >> time >> chores;

    int times[chores];
    for (int i = 0; i < chores; i++) {
        int temp;
        cin >> temp;
        times[i] = temp;
    }

    //sort array

    sort(times, times + chores);

    int total = 0;
    int count = 0;
    for (int i = 0; i < chores; i++) {
        if (total + times[i] <= time) {
            total += times[i];
            count++;
        }
    }

    cout << count << endl;
}