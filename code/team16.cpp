#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int main() {
    int col, row;
    cin >> col >> row;

    vector <vector<char> > v;
    for (int i = 0; i < row; i++) {
        vector<char> temp;
        for (int j = 0; j < col; j++) {
            char c;
            cin >> c;
            temp.push_back(c);
        }
        v.push_back(temp);
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    vector<vector<int> > distance (row, vector<int>(col, 1000000));
    distance[0][0] = 0;

    //queen moving
    vector<vector<int> > moves;// = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, -1}, {-1, 1}, {1, 1}};
    vector<int> temp1; temp1.push_back(1); temp1.push_back(0); moves.push_back(temp1);
    vector<int> temp2; temp2.push_back(-1); temp2.push_back(0); moves.push_back(temp2);
    vector<int> temp3; temp3.push_back(0); temp3.push_back(1); moves.push_back(temp3);
    vector<int> temp4; temp4.push_back(0); temp4.push_back(-1); moves.push_back(temp4);
    vector<int> temp5; temp5.push_back(1); temp5.push_back(-1); moves.push_back(temp5);
    vector<int> temp6; temp6.push_back(-1); temp6.push_back(-1); moves.push_back(temp6);
    vector<int> temp7; temp7.push_back(-1); temp7.push_back(1); moves.push_back(temp7);
    vector<int> temp8; temp8.push_back(1); temp8.push_back(1); moves.push_back(temp8);

    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        int r = temp.first;
        int c = temp.second;
        int cDist = distance[r][c];

        if (r < 0 || r >= row) continue;
        if (c < 0 || c >= col) continue;
        if (v[r][c] == '#') continue;

        if (r == row - 1 && c == col - 1) {
            break;
        }

        for (int i = 0; i < 8; i++) {
            int newr = r;
            int newc = c;
            while (true) {
                newr += moves[i][0];
                newc += moves[i][1];
                if (newr < 0 || newr >= row) break;
                if (newc < 0 || newc >= col) break;
                if (v[newr][newc] == '#') break;
                if (distance[newr][newc] != 1000000) continue;
                distance[newr][newc] = cDist + 1;
                q.push(make_pair(newr, newc));
            }
        }
    }

    cout << distance[row - 1][col - 1] << endl;
    
}
