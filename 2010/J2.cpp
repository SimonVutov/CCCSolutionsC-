#include <iostream>

int main() {
    int a, b, c, d, s;
    std::cin >> a >> b >> c >> d >> s;

    int Aat = 0;
    int Bat = 0;

    for (int i = 0; i < s; i++) {
        if (i % (a + b) < a) Aat++;
        else Aat--;
        if (i % (c + d) < c) Bat++;
        else Bat--;
    }

    if (Aat > Bat) std::cout << "Nikky";
    else if (Aat < Bat) std::cout << "Byron";
    else std::cout << "Tied";
}