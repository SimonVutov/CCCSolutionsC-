#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MAX_NUMS = 1000;  // Maximum number of elements
const int MAX_QUERY = 100; // Maximum query value

long long int powers[MAX_NUMS][MAX_QUERY + 1]; // DP array for powers

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    int nums, queries;
    cin >> nums >> queries;
    vector<int> numbers(nums);
    for (int i = 0; i < nums; i++) cin >> numbers[i];

    // Precompute and store powers in the DP array
    for (int i = 0; i < nums; i++) {
        powers[i][0] = 1;
        for (int j = 1; j <= MAX_QUERY; j++) {
            powers[i][j] = powers[i][j - 1] * numbers[i];
        }
    }

    for (int i = 0; i < queries; i++) {
        int query;
        int total = 0;
        cin >> query;

        if (query > 2) {
            cout << 0 << endl;
            continue;
        }

        unordered_map<long long int, int> contains;

        for (int j = 0; j < nums; j++) contains[powers[j][query]]++;

        for (int j = 0; j < nums; j++) {
            for (int k = j + 1; k < nums; k++) {
                total += 2 * contains[powers[j][query] + powers[k][query]];
            }
        }

        cout << total << endl;
    }

    return 0;
}
