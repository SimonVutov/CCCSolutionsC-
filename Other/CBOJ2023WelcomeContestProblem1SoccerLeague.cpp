#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
    int teams, games;
    cin >> teams >> games;

    vector<int> scores(teams, 0);

    for (int i = 0; i < games; i++) {
        int team1, team2, end;
        cin >> team1 >> team2 >> end;
        team1--;
        team2--;
        if (end == 0) {
            scores[team1] ++;
            scores[team2] ++;
        } else if (end == 1) {
            scores[team1] += 3;
        } else {
            scores[team2] += 3;
        }
    }

    for (int i = 0; i < teams; i++) {
        cout << scores[i] << endl;
    }
}