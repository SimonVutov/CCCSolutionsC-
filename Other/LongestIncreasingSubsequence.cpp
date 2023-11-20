#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++) { // n iterations, each iteration is O(log(n))
        if (ans.back() < v[i]) {
            ans.push_back(v[i]);
        } else {
            int ind = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[ind] = v[i];
        }
    }
    cout << ans.size() << endl;
}
