#include <iostream>
#include <map>
#include <string>

using namespace std;

void makeS(unordered_map<int, int> &subsequences, const string &s, int index) {
    // the amount of substrings endings by index

    if (index == s.size()) {
        return;
    }

    int current = 0;
    for (int i = 0; i < index; i++) {
        if (s[i] == s[index]) current += subsequences[i];
        else curent += subsequences[i] * 2;
    }
}

int main() {
    string s;
    cin >> s;
    int M;
    cin >> M;

    unordered_map<int, int> subsequences;
    subsequences[0] = 1;

    makeS(subsequences, s, 1);

    long long ans = 0;

    for (const auto &pair : subsequences) {
        ans += pair.second * pair.second;
        ans %= M;
    }

    cout << ans << endl;

    return 0;
}
