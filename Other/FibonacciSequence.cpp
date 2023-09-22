#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int nth;
    cin >> nth;

    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;

    double powphi = 1;
    double powpsi = 1;

    for (int i = 0; i < nth; i+= (min(nth - i, 1000))) {
        powphi *= pow(phi, min(nth - i, 1000));
        powpsi *= pow(psi, min(nth - i, 1000));
        powphi = fmod(powphi, 1000000007);
        powpsi = fmod(powpsi, 1000000007);
    }

    cout << int((powphi - powpsi) / sqrt(5)) % 1000000007 << endl;
    return 0;
}
