#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<char> > copy(vector<vector<char> >& v) {
    vector<vector<char> > temp(v.size(), vector<char>(v[0].size(), ' '));
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            temp[i][j] = v[i][j];
        }
    }
    return temp;
}

void drop (vector<vector<char>>& temp, vector<vector<char>>& grid, char type, int k) {
    int n = grid[0].size();
    for (int i = 0; i < n; i++) {
        if (i + k >= n) {
            break;
        }

        int aty = 0;
        for (int j = 0; j < grid.size(); j++) {
            if (grid[j][i] == '#') {
                aty = j;
                break;
            }
        }

        
    }
}

int main() {
    int n;
    cin >> n;

    /*
    T:    S:    Z:    L:    J:    O:    I:
     #     ##   ##      #   #     ##    ####
    ###   ##     ##   ###   ###   ##

    */

    vector<vector<string>> v(7, vector<string>(2, ""));
    v[0] = { " # ", "###" };
    v[1] = { " ##", "## " };
    v[2] = { "## ", " ##" };
    v[3] = { "  #", "###" };
    v[4] = { "#  ", "###" };
    v[5] = { "##", "##" };
    v[6] = { "####" };

    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;
        char type;
        cin >> type;

        vector<vector<char> > v(h, vector<char>(w, ' '));
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                cin >> v[j][k];
            }
        }

        vector<char> type = { 'T', 'S', 'Z', 'L', 'J', 'O', 'I' };

        for (int j = 0; j < 4; j++) {
            //for each rotation, drop it in and check amount of colls it clears
            vector<vector<char> > temp = copy(v);
            drop (temp, v[j], type[j], k);
        }
    }
}

/*
2
8 8 T
........
........
........
....#...
....##..
#...##.#
#..#####
#.##.###    1
10 6 L
..........
..........
.#........
#......#..
#....####.
#.########  0
*/