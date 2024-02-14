#include <iostream>
#include <unordered_set>
#include <string>
#include <functional>

using namespace std;

int main() {
    string input;
    cin >> input;
    string lastDir = "";
    while (input != "99999") {
        int n = input.length();
        int sum = stoi(input.substr(0, 1)) + stoi(input.substr(1, 1));
        if (sum == 0) {
            cout << lastDir << " " << input.substr(2,  n - 2) << endl;
        } else if (sum % 2 == 1) {
            lastDir = "left";
            cout << "left " << input.substr(2, n - 2) << endl;
        } else {
            lastDir = "right";
            cout << "right " << input.substr(2, n - 2) << endl;
        }
        cin >> input;
    }
}
