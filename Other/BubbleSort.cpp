#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    for (int j = 0; j < n; ++j) {
        cout << arr[j];
        if (j != n - 1) cout << " ";
    }
    cout << endl;
    
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                swapped = true;
                for (int j = 0; j < n; ++j) {
                    cout << arr[j];
                    if (j != n - 1) cout << " ";
                }
                cout << endl;
            }
        }
    } while (swapped);
    
    return 0;
}
