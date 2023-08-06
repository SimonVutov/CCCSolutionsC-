#include <iostream>

int main() {
    int A = 0, B = 0;

    int F = 0;
    std::cin >> F;

    while (F != 7) {
        if (F == 1) {
            char C;
            std::cin >> C;
            int val;
            std::cin >> val;
            if (C == 'A') A = val;
            else B = val;
        } else if (F == 2) {
            char C;
            std::cin >> C;
            if (C == 'A') std::cout << A << std::endl;
            else std::cout << B << std::endl;
        } else if (F == 3) { //MAY NOT BE RIGHT...
            char X, Y;
            std::cin >> X >> Y;
            if (X == 'A' && Y == 'A') A += B;
            else if (X == 'B' && Y == 'A') B += A;
        } else if (F == 4) {
            char X, Y;
            std::cin >> X >> Y;
            if (X == 'A' && Y == 'A') A *= B;
            else if (X == 'B' && Y == 'A') B *= A;
        } else if (F == 5) {
            char X, Y;
            std::cin >> X >> Y;
            if (X == 'A' && Y == 'A') A -= B;
            else if (X == 'B' && Y == 'A') B -= A;
        } else if (F == 6) {
            char X, Y;
            std::cin >> X >> Y;
            if (X == 'A' && Y == 'A') A /= B;
            else if (X == 'B' && Y == 'A') B /= A;
        }

        std::cin >> F;
    }
}