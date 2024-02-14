#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

int main() {
    int nums, queries;
    cin >> nums >> queries;
    vector<int> arr(nums);
    for (int i = 0; i < nums; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < queries; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        bool good = false; // all same checker, 0 checker
        int val = arr[l];
        bool thisg = true;
        for (int j = l; j <= r; j++) {
            if (arr[j] != val) {
                thisg = false;
                break;
            }
            if (arr[j] == 0) {
                good = true;
                break;
            }
        }
        if (thisg) {
            good = true;
        }

        // x and -x checker
        for (int j = l; j <= r; j++) {
            for (int k = j + 1; k <= r; k++) {
                if (arr[j] == -arr[k] || arr[k] == -arr[j]) {
                    good = true;
                    break;
                }
            }
        }

        // 

        if (good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
