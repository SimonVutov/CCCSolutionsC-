#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int minS(string line) {
    int changes = 0;
    char lastLet = line[0];
    for (int i = 1; i < line.size(); i++) {
        if (line[i] != lastLet) {
            changes++;
        }
        lastLet = line[i];
    }
    if (changes < 5) {
        cout << "done" << endl;
        return 0;
    }

    int count = 10e7;
    for (int i = 0; i < line.size(); i++) {
        for (int j = i+1; j < line.size(); j++) {
            char temp = line[i];
            line[i] = line[j];
            line[j] = temp;
            count = min(count, minS(line)+1);
            temp = line[i];
            line[i] = line[j];
            line[j] = temp;
        }
    }
    return count;
}

int main () {
    string line;
    cin >> line;
    cout << minS(line) << endl;
}