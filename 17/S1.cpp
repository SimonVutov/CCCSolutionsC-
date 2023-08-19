#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    int A[n];
    int B[n];

    int At = 0;
    int Bt = 0;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        A[i] = temp;
        At += temp;
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        B[i] = temp;
        Bt += temp;
    }
    
    
    for (int i = n - 1; i >= 0; i--) {

        if (At == Bt) {
            cout << i + 1 << endl;
            return 0;
        }
        
        At -= A[i];
        Bt -= B[i];
    }

    cout << 0 << endl;
}