#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int N, K;

int dfs (vector<vector<vector<char> > > &map, vector<vector<vector<int> > > &minD, int x, int y, int k, int distance = 0) {
    int onMap = (distance % (4 * k)) / k;
    cout << onMap << endl;
    cout << "hereq";

    //base cases, either out of bounds or in a wall, or made it :)
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return -1;
    }
    cout << "here3";
    if (map[x][y][onMap] == 'X') {
        return minD[x][y][onMap];
    }
    cout << "hereq5";
    if (map[x][y][onMap] == 'W') {
        return -1;
    }

    cout << "here2";

    // if we have already been here, and we have a better distance, return
    if (minD[x][y][onMap] != 0) {
        return -1;
    }

    cout << "here";

    // now move to the next spot
    vector<vector<int> > moves;
    vector<int> move1;
    move1.push_back(0);
    move1.push_back(1);
    moves.push_back(move1);
    move1[0] = 0;
    move1[1] = -1;
    moves.push_back(move1);
    move1[0] = 1;
    move1[1] = 0;
    moves.push_back(move1);
    move1[0] = -1;
    move1[1] = 0;
    moves.push_back(move1);

    for (int i = 0; i < moves.size(); i++) {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];
        int newD = minD[x][y][onMap] + 1;
        int newOnMap = (distance + 1) % (4 * k) / k;
        if (minD[newX][newY][newOnMap] == 0 || newD < minD[newX][newY][newOnMap]) {
            minD[newX][newY][newOnMap] = newD;
            int result = dfs(map, minD, newX, newY, k, distance + 1);
            if (result != -1) {
                return result;
            }
        }
    }

    return 1;
}

int main() {
    cin >> N >> K;
    vector<vector<vector<char> > > map (N, vector<vector<char> >(N, vector<char> (4, 0)));
    vector<vector<vector<int> > > minD (N, vector<vector<int> >(N, vector<int> (4, 0)));
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < N; j++) {
            map[i][j][0] = input[j];
        }
    }

    // fill map with all possible rotations
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j ++) {
            map[i][j][1] = map[N - j - 1][i][0];
            map[i][j][2] = map[N - i - 1][N - j - 1][0];
            map[i][j][3] = map[j][N - i - 1][0];
        }
    }

    int startX = 0, startY = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0 ; j < N; j++) {
            if (map[i][j][0] == 'E') {
                startX = i;
                startY = j;
            }
        }
    }

    cout << dfs(map, minD, startX, startY, K) << endl;
}
