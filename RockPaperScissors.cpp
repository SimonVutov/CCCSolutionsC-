#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int A=0, B=0, n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int Apoint=0, Bpoint=0;
        for (int j = 0; j < 5; j++){
            string a, b;
            cin >> a >> b; //R P S
            if (a == "R" && b == "S") Apoint++;
            else if (a == "S" && b == "P") Apoint++;
            else if (a == "P" && b == "R") Apoint++;
            else if (a == "R" && b == "P") Bpoint++;
            else if (a == "S" && b == "R") Bpoint++;
            else if (a == "P" && b == "S") Bpoint++;
        }
        if (Apoint > Bpoint) A++;
        else if (Bpoint > Apoint) B++;
    }
    if (A > B) cout << "A " << A-B << endl;
    else if (B > A) cout << "B " << B-A << endl;
    else cout << "TIE" << endl;
}
