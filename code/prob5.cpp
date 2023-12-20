#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int houses, candies;
    cin >> houses >> candies;
    vector<int> time(houses, 0);
    vector<int> candiesHouses(houses, 0);
    for (int i = 0; i < houses; i++) {
        cin >> time[i];
        cin >> candiesHouses[i];
    }

    vector<vector<int> > gridtime (houses + 1, vector<int>(3, 0));
    vector<vector<int> > gridpoints (houses + 1, vector<int>(3, 0));

    for (int i = 0; i < houses + 1; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1) gridtime[i][j] = 1;
            else if (i % 2 == 1) {
                gridtime[i][j] = time[i - 1 + j/2];
                gridpoints[i][j] = candiesHouses[i - 1 + j/2];
            }
            else gridtime[i][j] = -10000000;
        }
    }

    // priority queue, max points starting c = 1, r = 0;

    priority_queue<pair<pair<int, int>, pair<int, int> > > pq;

    //pq.push(make_pair(gridpoints[0][1], make_pair(0, 1)));
    pq.push(make_pair(make_pair(gridpoints[0][1], gridtime[0][1]), make_pair(0, 1)));

    while (!pq.empty()) {
        pair <pair<int, int>, pair<int, int> > temp = pq.top();
        pq.pop();
        int points = temp.first.first;
        int time = temp.second.first;
        int r = temp.second.first;
        int c = temp.second.second;

        if (r > houses) continue;
        if (r < 0) continue;

        if (gridtime[r][c] == -10000000) continue;

        if (points >= candies) {
            cout << points << endl;
            cout << time << endl;
            break;
        }

        if (r >= houses) {
            continue;
        }

        if (c == 0) {
            // go left
            //pq.push(make_pair(points + gridpoints[r][1], make_pair(r, 1)));
            pq.push(make_pair(make_pair(points + gridpoints[r][1], time + gridtime[r][1]), make_pair(r, 1)));
        }
        else if (c == 1) {
            // go up and down
            pq.push(make_pair(make_pair(points + gridpoints[r][0], time + gridtime[r-1][1]), make_pair(r - 1, 1)));
            pq.push(make_pair(make_pair(points + gridpoints[r][2], time + gridtime[r+1][1]), make_pair(r + 1, 1)));
        }
        else {
            //go right
            //pq.push(make_pair(points + gridpoints[r][1], make_pair(r, 1)));
            pq.push(make_pair(make_pair(points + gridpoints[r][1], time + gridtime[r][1]), make_pair(r, 1)));
        }
    }
}
