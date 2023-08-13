#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int main () {
    int N = 0;
    cin >> N;
    int inconveniences = 0;
    int printedAnOddFirst = 0;

    vector<int> pages;
    vector<int> ans;
    vector<int> ans2;
    for (int i = 0; i < N; i++) {
        int page; cin >> page;
        pages.push_back(page);
    }

    for (int i = 0; i < N; i++) {
        if (pages[i] % 2 != 0 && pages[i] != -1){
            ans.push_back(i + 1);
            inconveniences += floor(pages[i] / 2);
            pages[i] = -1;
            printedAnOddFirst = 1;
            break;
        }
    }

    for (int i = 0; i < (int)pages.size(); i++) {
        if (pages[i] % 2 == 0 && pages[i] != -1){
            ans.push_back(i + 1);
            inconveniences += pages[i] / 2 - printedAnOddFirst;
        } else if (pages[i] % 2 != 0 && pages[i] != -1){
            ans2.push_back(i + 1);
            inconveniences += pages[i] / 2;
        }
        pages[i] = -1;
    }

    cout << inconveniences << endl;

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    for (int i = 0; i < (int)ans2.size(); i++) {
        cout << ans2[i] << " ";
    }

    return 0;
}