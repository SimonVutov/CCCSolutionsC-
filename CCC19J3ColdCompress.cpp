#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int count = 1;
        for (int j = 0; j < (int)s.length(); j++) {
            if (s[j] == s[j+1]) {
                count++;
            } else {
                cout << count << " " << s[j] << " ";
                count = 1;
            }
        }
        cout << endl;
    }
}
