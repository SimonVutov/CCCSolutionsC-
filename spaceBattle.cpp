#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t, h, d, r;
    cin >> t >> h >> d >> r; //enemy spaceships, my health, my damage, my reload time
    //enemy health, dmaage, reload time
    vector<int> health (t, 0), damage (t, 0), reload (t, 0);
    for (int i = 0; i < t; i++) cin >> health[i] >> damage[i] >> reload[i];

    vector<int> healthTaken (t, 0); //health taken from each enemy in a battle

    for (int i = 0; i < t; i++) {
        int time = (ceil((double)health[i]/(double)d) - 1) * r;
        int damageTaken = floor((double)time / reload[i] + 1) * damage[i];
        healthTaken[i] = damageTaken;
    }
    sort (healthTaken.begin(), healthTaken.end());
    int total = 0;
    int at = 0;
    while (h > 0) {
        if (healthTaken[at] == -1) continue;
        if (healthTaken[at] > h) break;
        h -= healthTaken[at];
        total++;
        at++;
    }

    cout << total << endl;
}
