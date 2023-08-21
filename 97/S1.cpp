#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int subjects, verbs, objects;
        cin >> subjects >> verbs >> objects;
        vector<string> subject, verb, object;
        cin.ignore();
        for (int j = 0; j < subjects; j++) {
            string s;
            getline(cin, s);
            subject.push_back(s);
        }
        for (int j = 0; j < verbs; j++) {
            string s;
            getline(cin, s);
            verb.push_back(s);
        }
        for (int j = 0; j < objects; j++) {
            string s;
            getline(cin, s);
            object.push_back(s);
        }

        int p = subjects*verbs*objects;
        int count = 0;
        vector<string> sentence (p);
        for (int j = 0; j < subjects; j++) {
            for (int k = 0; k < verbs; k++) {
                for (int l = 0; l < objects; l++) {
                    sentence[count] = subject[j] + " " + verb[k] + " " + object[l] + ".";
                    count++;
                }
            }
        }

        //print sentence
        for (int j = 0; j < p; j++) {
            cout << sentence[j] << endl;
        }
    }
}