#include <iostream>
#include "queue"
#include "unordered_map"

using namespace std;

int main() {
    int in, res = 0;
    cin >> in;
    while (in >= 1111) {
        res++;
        in -= 1111;
    }
    cout << res + in;
}