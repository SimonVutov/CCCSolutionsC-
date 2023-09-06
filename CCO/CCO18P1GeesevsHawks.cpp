#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std; //no memoization

int maxPoints (string a, int arr[], string b, int brr[], vector<int> mA, vector<int> mB) {
    int maxP = 0;
    for (int i = 0; i < (int)a.length(); i++) { //for each a
        for (int j = 0; j < (int)b.length(); j++) { //for each b

            //check so times dont overlap
            bool skip = false;
            for (int k = 0; k < (int)a.length(); k++) {
                for (int l = 0; l < (int)b.length(); l++) {
                    if (mA[k] > j && mB[l] < i) skip = true;
                    if (mA[k] < j && mB[l] > i) skip = true;
                }
            }

            if (skip) continue;
            if (a[i] == 'W' && b[j] == 'L' && arr[i] > brr[j] && arr[i] != -1 && brr[j] != -1) {
                a[i] = '-';
                b[j] = '-';
                int temp1 = arr[i];
                int temp2 = brr[j];
                arr[i] = -1;
                brr[j] = -1;
                mA[i] = j;
                mB[j] = i;
                maxP = max(maxP, temp1 + temp2 + maxPoints(a, arr, b, brr, mA, mB));
                mA[i] = -1;
                mB[j] = -1;


                a[i] = 'W';
                b[j] = 'L';
                arr[i] = temp1;
                brr[j] = temp2;
            } else if (a[i] == 'L' && b[j] == 'W' && arr[i] < brr[j] && arr[i] != -1 && brr[j] != -1) {
                a[i] = '-';
                b[j] = '-';
                int temp1 = arr[i];
                int temp2 = brr[j];
                arr[i] = -1;
                brr[j] = -1;
                mA[i] = j;
                mB[j] = i;
                maxP = max(maxP, temp1 + temp2 + maxPoints(a, arr, b, brr, mA, mB));
                mA[i] = -1;
                mB[j] = -1;

                a[i] = 'L';
                b[j] = 'W';
                arr[i] = temp1;
                brr[j] = temp2;
            }
        }
    }
    return maxP;
}

int main () {
    int n;
    cin >> n;

    string A;
    cin >> A;
    int Arr[n];
    for (int i = 0; i < n; i++) cin >> Arr[i];

    string B;
    cin >> B;
    int Brr[n];
    for (int i = 0; i < n; i++) cin >> Brr[i];
    

    vector<int> matchedA (n, -1);
    vector<int> matchedB (n, -1);
    cout << maxPoints(A, Arr, B, Brr, matchedA, matchedB);
}