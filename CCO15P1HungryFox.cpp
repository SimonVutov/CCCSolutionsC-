#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    sort(temp.begin(), temp.end());

    int minV = temp[n - 1] - temp[0];

    int maxV = 0;

    int curTemp = w;

    int lowID = 0;
    int highID = n - 1;

    //go to furthest, either minTemp, maxTemp, or waterTemp

    while (lowID <= highID) {
        int lowTemp = temp[lowID];
        int highTemp = temp[highID];
        int waterTemp = w;

        int lowDiff = abs(curTemp - lowTemp);
        int highDiff = abs(curTemp - highTemp);
        int waterDiff = abs(curTemp - waterTemp);

        if (lowDiff < highDiff && waterDiff < highDiff) {
            maxV += highDiff;
            curTemp = highTemp;
            highID--;
        } else if (highDiff < lowDiff && waterDiff < lowDiff) {
            maxV += lowDiff;
            curTemp = lowTemp;
            lowID++;
        } else if (lowDiff < waterDiff && highDiff < waterDiff) {
            maxV += waterDiff;
            curTemp = waterTemp;
            lowID++;
            highID--;
        } else if (lowDiff < waterDiff) {
            maxV += waterDiff;
            curTemp = waterTemp;
            lowID++;
        } else if (highDiff < waterDiff) {
            maxV += waterDiff;
            curTemp = waterTemp;
            highID--;
        } else {
            maxV += lowDiff;
            curTemp = lowTemp;
            lowID++;
        }

        cout << maxV << endl;
    }

    cout << minV << " " << maxV << endl;
}
