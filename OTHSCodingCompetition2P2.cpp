#include <iostream>

using namespace std;

int main() {
    int myS;
    cin >> myS;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        if (myS <= s) {
            cout << "fight";
            return 0;
        }
    }
    cout << "run away";
}