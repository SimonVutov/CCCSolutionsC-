#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main () {
    int n = 0;
    cin >> n;

    string topName = "";
    int topScore = 0;
    string topName2 = "";
    int topScore2 = 0;


    for (int i = 0; i < n; i++) {
        string name = "";
        int R, S, D;
        cin >> name >> R >> S >> D;
        int score = 2 * R + 3 * S + D;
        if (topName == "") {
            topName = name;
            topScore = score;
        } else if (score > topScore || (score == topScore && name < topName)) {
            topName2 = topName;
            topScore2 = topScore;
            topName = name;
            topScore = score;
        } else if (topName2 == "") {
            topName2 = name;
            topScore2 = score;
        } else if (score > topScore2) {
            topName2 = name;
            topScore2 = score;
        }
    }
    if (topScore == topScore2) {
        if (topName < topName2) cout << topName << endl << topName2 << endl;
        else cout << topName2 << endl << topName << endl;
    } else cout << topName << endl << topName2 << endl;   
}