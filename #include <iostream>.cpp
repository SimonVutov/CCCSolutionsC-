#include <iostream>
#include <vector>
#include <algorithm>

struct Piece {
    int index;
    int pages;
    int inconvenience;
};

bool compare(const Piece &a, const Piece &b) {
    return a.inconvenience < b.inconvenience;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Piece> pieces(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> pieces[i].pages;
        pieces[i].index = i + 1;
        if (pieces[i].pages % 2 == 0) {
            pieces[i].inconvenience = (pieces[i].pages / 2);
        } else {
            pieces[i].inconvenience = (pieces[i
