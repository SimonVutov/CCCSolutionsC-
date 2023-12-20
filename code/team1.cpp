#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> xCor (n, 0);
    vector<int> yCor (n, 0);
    vector<int> xVel (n, 0);
    vector<int> yVel (n, 0);
    for (int i = 0; i < n; i++) {
        cin >> xCor[i] >> yCor[i] >> xVel[i] >> yVel[i];
    }

    double minCollisionMillis = 1001;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //check if i and j collide, set mintime
            
            //find coords of intersection
            double xInt = 0, yInt = 0;

            double m1 = (double)yVel[i] / (double)xVel[i];
            double m2 = (double)yVel[j] / (double)xVel[j];
            double b1 = yCor[i] - m1 * xCor[i];
            double b2 = yCor[j] - m2 * xCor[j];

            if (m1 == m2) {
                double overallVelocity = sqrt(pow(xVel[i] - xVel[j], 2) + pow(yVel[i] - yVel[j], 2));
                double overallDistance = sqrt(pow(xCor[i] - xCor[j], 2) + pow(yCor[i] - yCor[j], 2));
                double time = overallDistance / overallVelocity;
                //check if in bounds
                if (xVel[i] * time >= 0 && xVel[i] * time <= x && yVel[i] * time >= 0 && yVel[i] * time <= y) {
                    minCollisionMillis = min(minCollisionMillis, time);
                }
            }

            xInt = (b2 - b1) / (m1 - m2);
            yInt = m1 * xInt + b1;

            double time1 = 0, time2 = 0;
            
            double dist1 = sqrt(pow(xInt - xCor[i], 2) + pow(yInt - yCor[i], 2));
            double dist2 = sqrt(pow(xInt - xCor[j], 2) + pow(yInt - yCor[j], 2));

            double speed1 = sqrt(pow(xVel[i], 2) + pow(yVel[i], 2));
            double speed2 = sqrt(pow(xVel[j], 2) + pow(yVel[j], 2));

            time1 = dist1 / speed1;
            time2 = dist2 / speed2;

            if (time1 == time2 && xInt >= 0 && xInt <= x && yInt >= 0 && yInt <= y) {
                minCollisionMillis = min(minCollisionMillis, time1);
            }
        }
    }

    if (minCollisionMillis == 1001) cout << "No collision" << endl;
    else cout << (int)minCollisionMillis << endl;
}
