#include <vector>
#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < b.size(); i++) {
        //check if b is contained in a
        if (a.find(b) != string::npos) {
            cout << "yes" << endl;
            return 0;
        }
        //shift b
        b = b[b.size() - 1] + b.substr(0, b.size() - 1);
    }
    cout << "no" << endl;
}