#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <cctype>
using namespace std; //NO

int main() {
    int N, H, P;
    cin >> N >> H >> P;
    vector<int> bosses(N);
    int maxVal = 0;
    for (int i = 0; i < N; i++) {
        cin >> bosses[i];
        if (bosses[i] > maxVal) {
            maxVal = bosses[i];
        }
    }

    vector<int> arr (maxVal);
    int minVal = 1000000000;
    for (int i = 0; i < maxVal; i++) {
        arr[i] += i * H;
        for (int j = 0; j < N; j++) {
            if (bosses[j] > i) {
                arr[i] += (bosses[j] - i) * P;
            }
        }

        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    cout << minVal << endl;
}
