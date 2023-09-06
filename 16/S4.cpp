#include <iostream>
#include <vector>
using namespace std;

int riceBalls[400];
vector<vector<int> > counts (400, vector<int> (400, -1));
int n;

bool can_combine(int start, int end) {
    return start == end || counts[start][end] != -1;
}

int range_count(int start, int end) {
    return start == end ? riceBalls[start] : counts[start][end];
}

bool two_blocks(int first_start, int last_end) {
    for (int last_start = first_start + 1; last_start <= last_end; last_start++) {
        int first_end = last_start - 1;

        if (!can_combine(first_start, first_end) || !can_combine(last_start, last_end)) continue;

        int first_count = range_count(first_start, first_end);
        int last_count = range_count(last_start, last_end);

        if (first_count != last_count) continue;

        counts[first_start][last_end] = first_count + last_count;
        return true;
    }

    return false;
}

void three_blocks(int first_start, int last_end) {
    for (int middle_start = first_start + 1; middle_start < last_end; middle_start++) {
        int first_end = middle_start - 1;

        if (!can_combine(first_start, first_end)) continue;

        int first_count = range_count(first_start, first_end);

        for (int last_start = middle_start + 1; last_start <= last_end; last_start++) {
            int middle_end = last_start - 1;

            if (!can_combine(middle_start, middle_end) || !can_combine(last_start, last_end)) continue;

            int last_count = range_count(last_start, last_end);

            if (first_count != last_count) continue;

            int middle_count = range_count(middle_start, middle_end);
            counts[first_start][last_end] = first_count + middle_count + last_count;
            return;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> riceBalls[i];

    for (int range = 2; range <= n; range++) {
        for (int first_start = 0; first_start <= n - range; first_start++) {
            int last_end = first_start + range - 1;
            bool found = two_blocks(first_start, last_end);
            if (found || (range > 2)) three_blocks(first_start, last_end);
        }
    }

    int max_count = 0;
    for (int start = 0; start < n; start++) for (int end = start; end < n; end++) max_count = max(max_count, counts[start][end]);
    cout << max_count << endl;
}
