#include <iostream>
#include <vector>
using namespace std;

int ma (int k, int w, vector<int> pins) {
    if (k == 0) return 0;
    int most = 0;
    for (int i = 0; i < (int)pins.size() - w + 1; i++) {
        int sum = 0;
        vector<int> temp (w);
        for (int j = i; j < i + w; j++) {
            sum += pins[j];
            temp[j - i] = pins[j];
            pins[j] = 0;
        }
        most = max(most, sum + ma(k - 1, w, pins));
        for (int j = i; j < i + w; j++) {
            pins[j] = temp[j - i];
        }
    }
    return most;
}

int main() {
    int r;
    cin >> r;
    for (int i = 0; i < r; i++) {
        int n, k, w; //pins, balls, adjacent
        cin >> n >> k >> w;

        vector<int> pins(n);
        for (int j = 0; j < n; j++) cin >> pins[j];
        cout << ma(k, w, pins) << endl;
    }
}
