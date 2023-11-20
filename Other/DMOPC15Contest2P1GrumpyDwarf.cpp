#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int steal, conversion;
    cin >> steal >> conversion;
    int swords = 0;
    int curentSwordsOwned = 0;
    while (steal != 0) {
        swords += steal;
        curentSwordsOwned += steal;
        steal = 0;
        if (curentSwordsOwned >= conversion) {
            steal = curentSwordsOwned / conversion;
            curentSwordsOwned = curentSwordsOwned % conversion;
        } else {
            break;
        }
    }
    cout << swords << endl;
}