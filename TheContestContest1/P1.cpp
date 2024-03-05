#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> scores(n, 0);
    string s;
    cin >> s;

    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'Y') {
            sum = i + 1;
            break;
        }
    }

    if (sum > n/2) cout << "YES" << endl;
    else cout << "NO" << endl;

    
}
