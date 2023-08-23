#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;

        vector<int> input;
        vector<int> bin;

        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            input.push_back(temp);
        }

        int num = 1;

        while (true) {
            if (input.size() > 0 && input.back() == num) {
                input.pop_back();
                num++;
            } else if (bin.size() > 0 && bin.back() == num) {
                bin.pop_back();
                num++;
            } else if (input.size() > 0) {
                bin.push_back(input.back());
                input.pop_back();
            } else {
                break;
            }
        }

        cout << (bin.size() == 0 ? "Y" : "N") << endl;
    }
}
