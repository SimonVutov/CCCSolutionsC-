#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T, N; //num strings, len of strings
    cin >> T >> N;
    for (int i = 0; i < T; i++) {
        string str;
        cin >> str;
        unordered_map<char, int> m;
        for (int j = 0; j < N; j++) {
            m[str[j]]++;
        }

        bool try1 = true;
        for (int j = 0; j < N; j+=2) if (m[str[j]] > 1) try1 = false;
        for (int j = 1; j < N; j+=2) if (m[str[j]] <= 1) try1 = false;

        bool try2 = true;
        for (int j = 0; j < N; j+=2) if (m[str[j]] <= 1) try2 = false;
        for (int j = 1; j < N; j+=2) if (m[str[j]] > 1) try2 = false;

        if (try1 || try2) cout << "T" << endl;
        else cout << "F" << endl;
    }

    return 0;
}
