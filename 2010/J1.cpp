#include <iostream>

int main() {

    //input N
    int N;
    std::cin >> N;
    
    //1: 1, 2: 2, 3: 2, 4: 3, 5: 3, 6: 3, 7: 2, 8: 2, 9: 1, 10: 1
    if (N == 1) {
        std::cout << 1;
    } else if (N == 2 || N == 3) {
        std::cout << 2;
    } else if (N == 4 || N == 5 || N == 6) {
        std::cout << 3;
    } else if (N == 7 || N == 8) {
        std::cout << 2;
    } else {
        std::cout << 1;
    }

    return 0;
}