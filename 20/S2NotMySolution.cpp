#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Cell {
    public:
    int r;
    int c;
};

bool searched[1010][1010];
vector<vector<Cell> > vals(1000010);

string is_possible(Cell last_cell) {
    queue<Cell> q;
    q.push(last_cell);
    while (!q.empty()) {
        Cell cell = q.front();
        cout << cell.r << " " << cell.c << endl;
        q.pop();
        vector<Cell> neighbors = vals[cell.r * cell.c];
        for (Cell neighbor: neighbors) {
            if (neighbor.r == 1 && neighbor.c == 1) {
                return "yes";
            } else if (!searched[neighbor.r][neighbor.c]) {
                searched[neighbor.r][neighbor.c] = true;
                q.push(neighbor);
            }
        }
    }
    return "no";
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    Cell last_cell;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            int val;
            cin >> val;
            Cell cell;
            cell.r = i; cell.c = j;
            vals[val].push_back(cell);

            if (i == rows && j == cols) {
                last_cell = cell;
            }
        }
    }
    cout << is_possible(last_cell);
    return 0;
}