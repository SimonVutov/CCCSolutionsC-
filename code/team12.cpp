#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

struct Point {
    int at;
    int time;
    int flights;
    int cost;

    Point() : at(0), time(0), flights(0), cost(0) {}
};

int main() {
    int a, b, n, t, k; //start, end, num flights, max time, max flights
    cin >> a >> b >> n >> t >> k;
    vector<int> starts(n, 0), ends(n, 0), costs(n, 0), times(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> starts[i] >> ends[i] >> costs[i] >> times[i];
    }

    //priority queue, smallest cost
    priority_queue<pair<int, Point> > pq;
    Point p = Point();
    p.at = a;
    p.time = 0;
    pq.push(make_pair(0, p));

    while (!pq.empty()) {
        pair<int, Point> temp = pq.top();
        pq.pop();
        int cost = temp.first;
        int at = temp.second.at;
        int time = temp.second.time;
        int flights = temp.second.flights;

        if (at == b) {
            cout << cost << " " << time << endl;
            break;
        }

        if (time > t) continue;
        if (flights > k) continue;

        for (int i = 0; i < n; i++) {
            if (starts[i] == at) {
                Point p = Point();
                p.at = ends[i];
                p.time = time + times[i];
                p.flights = flights + 1;
                p.cost = cost + costs[i];
                pq.push(make_pair(cost + costs[i], p));
            }
        }
    }

    return 0;
}
