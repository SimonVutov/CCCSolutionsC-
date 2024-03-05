#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    string s1 = "", s2 = "";

    s1 = to_string(a[0]);
    s2 = to_string(b[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            s1 += to_string(a[i]);
        }
        if (b[i] != b[i - 1]) {
            s2 += to_string(b[i]);
        }
    }

    int i = 0;
    for (int j = 0; j < s1.size(); j++) {
        if (s1[j] == s2[i]) {
            i++;
        }
    }
    

    stringstream seq;
    int times = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;

        int start = i;
        while (start < n - 1 && a[start] != b[i]) start++;

        if (start == i) continue;

        //right swipe from start to i inclusive
        for (int j = i; j <= start; j++) {
            a[j] = a[start];
        }
        seq << "R " << i << " " << start << endl;
        times++;
    }

    for (int i = n-1; i >= 0; i--) {
        if (a[i] == b[i]) continue;

        int start = i;
        while (start > 0 && a[start] != b[i]) start--;

        if (start == i) continue;

        //right swipe from start to i inclusive
        for (int j = start; j <= i; j++) {
            a[j] = a[start];
        }
        seq << "R " << start << " " << i << endl;
        times++;
    }

    


    if (i == s2.size()) {
        cout << "YES" << endl;
        cout << times << endl;
        cout << seq.str();
    }
    else cout << "NO" << endl;
}
