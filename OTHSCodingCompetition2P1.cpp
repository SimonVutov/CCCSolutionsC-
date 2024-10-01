#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    //queen worth 9, a rook worth 5, a bishop and a knight worth 3 each, a pawn worth 1, and the king being priceless
    if (s == "queen") {
        cout << 9;
    } else if (s == "rook") {
        cout << 5;
    } else if (s == "bishop" || s == "knight") {
        cout << 3;
    } else if (s == "pawn") {
        cout << 1;
    } else {
        cout << "priceless";
    }
}