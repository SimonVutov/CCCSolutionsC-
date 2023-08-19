#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int totalWinScenarios (vector<vector<int> > g, int fav) {
    bool done = true;
    int maxVal = 0;
    int maxTeam = 0;
    for (int i = 0; i < 4; i++) {
        int cur = 0;
        for (int j = 0; j < 4; j++) {
            if (g[i][j] == -1 && i != j) done = false;
            cur += g[i][j];
        }
        if (cur > maxVal) {
            maxVal = cur;
            maxTeam = i;
        }
    }
    if (done) {if (maxTeam == fav) return 1; else return 0;}

    int total = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (g[i][j] == -1) {
                g[i][j] = 3;
                g[j][i] = 0;
                total += totalWinScenarios(g, fav);
                g[i][j] = 0;
                g[j][i] = 3;
                total += totalWinScenarios(g, fav);
                g[i][j] = 1;
                g[j][i] = 1;
                total += totalWinScenarios(g, fav);
                g[i][j] = -1;
                g[j][i] = -1;
            }
        }
    }

    return total;
}

int main () {
    int fav, gamesPlayed;
    cin >> fav;
    cin >> gamesPlayed;
    fav--;
    vector<vector<int> > v(4, vector<int>(4, -1));
    // 3 = win, 0 = loss, 1 = tie, -1 = not played
    // v[0][3] means team 0 played team 3 and team 0 got x points from that game

    for (int i = 0; i < gamesPlayed; i++) {
        int team1, team2, score1, score2;
        cin >> team1 >> team2 >> score1 >> score2;
        team1--; team2--;
        if (score1 > score2) {
            v[team1][team2] = 3;
            v[team2][team1] = 0;
        } else if (score1 < score2) {
            v[team1][team2] = 0;
            v[team2][team1] = 3;
        } else {
            v[team1][team2] = 1;
            v[team2][team1] = 1;
        }
    }

    cout << totalWinScenarios(v, fav) << endl;
}