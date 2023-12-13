#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

struct sec {
    int S = 0;
    int M = 0;
    int L = 0;
};

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int S = 0, M = 0, L = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') S++;
        else if (s[i] == 'M') M++;
        else L++;
    }

    sec Ls, Ms, Ss;
    for (int i = 0; i < L; i++) {
        if (s[i] == 'S') Ss.L++;
        else if (s[i] == 'M') Ms.L++;
        else Ls.L++;
    }
    for (int i = L; i < L + M; i++) {
        if (s[i] == 'S') Ss.M++;
        else if (s[i] == 'M') Ms.M++;
        else Ls.M++;
    }
    for (int i = L + M; i < L + M + S; i++) {
        if (s[i] == 'S') Ss.S++;
        else if (s[i] == 'M') Ms.S++;
        else Ls.S++;
    }

    int ans = 0;
    int justAdded = 0;

    justAdded = min(Ls.M, Ms.L);
    ans += justAdded;
    Ls.M -= justAdded;
    Ms.L -= justAdded;

    justAdded = min(Ls.S, Ss.L);
    ans += justAdded;
    Ls.S -= justAdded;
    Ss.L -= justAdded;

    justAdded = min(Ms.S, Ss.M);
    ans += justAdded;
    Ms.S -= justAdded;
    Ss.M -= justAdded;

    justAdded = max(Ls.M, Ls.S);
    justAdded = min(max(Ms.S, Ms.L), justAdded);
    justAdded = min(max(Ss.M, Ss.L), justAdded);
    ans += justAdded * 2;

    cout << ans << endl;
}
