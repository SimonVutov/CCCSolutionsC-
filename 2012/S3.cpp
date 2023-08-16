#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    
    int a[1005];

    for (int i = 0; i < 1005 - 1; i++) {
        a[i] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        a[x]++;
    }

    int aOcc = 0;
    int aOccAmount = 0;
    int bOcc = 0;
    int bOccAmount = 0;
    int aVal = 0;
    int bVal = 0;

    for (int i = 0; i < 1005; i++) {
        if (a[i] > aOcc) {
            bOcc = aOcc;
            bOccAmount = aOccAmount;
            aOcc = a[i];
            aOccAmount = 1;
            aVal = i;
        } else if (a[i] == aOcc) {
            aOccAmount++;
        } else if (a[i] > bOcc) {
            bOcc = a[i];
            bOccAmount = 1;
            bVal = i;
        } else if (a[i] == bOcc) {
            bOccAmount++;
        }
    }

    if (aOccAmount > 1) {
        int smallest = 10e7;
        int largest = 0;

        for (int i = 0; i < 1005; i++) {
            if (a[i] == aOcc) {
                if (i < smallest) {
                    smallest = i;
                }
                if (i > largest) {
                    largest = i;
                }
            }
        }

        cout << (largest - smallest) << endl;
    } else if (aOccAmount == 1 && bOccAmount > 1){
        int ax = aVal;
        int largestDiff = 0;
        for (int i = 0; i < 1005; i++) {
            if (a[i] == bOcc) {
                if (abs(ax - i) > largestDiff) {
                    largestDiff = abs(ax - i);
                }
            }
        }

        cout << largestDiff << endl;
    } else if (aOccAmount == 1 && bOccAmount == 1) {
        cout << max(aVal - bVal, bVal - aVal) << endl;
    }
}