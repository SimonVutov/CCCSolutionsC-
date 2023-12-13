#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    //num customers, num pizza slices per pizza, num ovens, time per pizza
    int n, s, o, t;
    cin >> n >> s >> o >> t;
    unordered_map<string, int> pizzas;
    for (int i = 0; i < n; i++) {
        int slices;
        string pizza;
        cin >> slices >> pizza;
        pizzas[pizza] += slices;
    }

    int total = 0;
    for (auto it = pizzas.begin(); it != pizzas.end(); it++) {
        int pizzasNeeded = ceil((double)it->second / s);
        total += pizzasNeeded;
    }

    cout << ceil((double)total / (double)o) * t << endl;
}
