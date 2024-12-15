#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int required_score = 80 * (b + 1) - a * b;
    
    if (required_score > 100) {
        cout << -1 << endl; // Impossible to achieve
    } else if (required_score <= 0) {
        cout << 0 << endl; // Minimum score needed is 0
    } else {
        cout << required_score << endl; // Output the required score
    }
    return 0;
}