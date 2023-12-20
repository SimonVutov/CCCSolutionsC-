#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    int N, R, r, vx, vy; //num pints, r of ball, r of pins, xvel, yvel
    cin >> N >> R >> r >> vx >> vy;

    vector<Point> pins(N);
    for (int i = 0; i < N; i++) {
        cin >> pins[i].x >> pins[i].y;
    }

    if (vx == 0) {
        int count = 0;
        //count pins that are close to vertical line
        for (int i = 0; i < N; i++) {
            if (vy > 0) {
                if (abs(pins[i].x) <= r + R && sqrt(pow(pins[i].y, 2) + pow(pins[i].x, 2)) < 0) {
                    count++;
                }
            }
            else {
                if (abs(pins[i].x) <= r + R && sqrt(pow(pins[i].y, 2) + pow(pins[i].x, 2)) < 0) {
                    count++;
                }
            }
        }
        cout << count << endl;
        return 0;
    }

    if (vy == 0) {
        int count = 0;
        //count pins that are close to horizontal line
        for (int i = 0; i < N; i++) {
            if (vx > 0) {
                if (abs(pins[i].y) <= r + R && pins[i].x > 0) {
                    count++;
                }
            }
            else {
                if (abs(pins[i].y) <= r + R && pins[i].x < 0) {
                    count++;
                }
            }
        }
        cout << count << endl;
        return 0;
    }

    double lineM = vy / vx;
    double lineB = 0;

    int count = 0;
    for (int i = 0; i < N; i++) {
        double pinM = -1/lineM;
        double pinB = pins[i].y - pinM * pins[i].x;

        double xInt = (pinB - lineB) / (lineM - pinM);
        double yInt = pinM * xInt + pinB;
        if ((sqrt(pow(xInt - pins[i].x, 2) + pow(yInt - pins[i].y, 2)) <= r + R && xInt > 0 && yInt > 0) || (sqrt(pow(0 - pins[i].x, 2) + pow(0 - pins[i].y, 2)) <= r + R)) {
            count++;
        }
    }
    
    cout << count << endl;

    return 0;
}