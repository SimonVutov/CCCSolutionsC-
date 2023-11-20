#include <iostream>
#include <vector>
using namespace std;

int main() {
    int I, N, J;
    cin >> I >> N >> J;
    vector<int> pos (I, 0);
    for (int i = 0; i < J; i++) {
        int start, end, num;
        cin >> start >> end >> num;
        pos[start - 1] += num;
        if (end < I) {
            pos[end] -= num;
        }
    }

    int numStations = 0;
    int curAmount = 0;
    for (int i = 0; i < I; i++) {
        curAmount += pos[i];
        if (curAmount < N) {
            numStations++;
        }
    }

    cout << numStations << endl;
}