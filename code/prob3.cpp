#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    string w1, m1, d1, y1;
    string w2, m2, d2, y2;
    cin >> w1 >> m1 >> d1 >> y1;
    cin >> w2 >> m2 >> d2 >> y2;

    d1 = d1.substr(0, d1.length() - 1);
    d2 = d2.substr(0, d2.length() - 1);

    int year1 = stoi(y1);
    int year2 = stoi(y2);

    int day1 = stoi(d1);
    int day2 = stoi(d2);

    w1 = w1.substr(0, w1.length() - 1);
    w2 = w2.substr(0, w2.length() - 1);

    vector<string> days;// = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    days.push_back("Monday"); days.push_back("Tuesday"); days.push_back("Wednesday"); days.push_back("Thursday"); days.push_back("Friday"); days.push_back("Saturday"); days.push_back("Sunday");
    vector<string> months; // = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    months.push_back("January"); months.push_back("February"); months.push_back("March"); months.push_back("April"); months.push_back("May"); months.push_back("June"); months.push_back("July"); months.push_back("August"); months.push_back("September"); months.push_back("October"); months.push_back("November"); months.push_back("December");

    vector<int> monthDays;// = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    monthDays.push_back(31); monthDays.push_back(28); monthDays.push_back(31); monthDays.push_back(30); monthDays.push_back(31); monthDays.push_back(30); monthDays.push_back(31); monthDays.push_back(31); monthDays.push_back(30); monthDays.push_back(31); monthDays.push_back(30); monthDays.push_back(31);
    int friday13ths = 0;

    while (true) {

        if (w1 == "Friday" && day1 == 13) {
            friday13ths++;
        }

        //take a step
        day1++;
        if (day1 > monthDays[find(months.begin(), months.end(), m1) - months.begin()]) {
            if (((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0)) && m1 == "February") {
                if (day1 > 29) {
                    day1 = 1;
                    m1 = months[(find(months.begin(), months.end(), m1) - months.begin() + 1) % 12];
                }
            } else {
                day1 = 1;
                m1 = months[(find(months.begin(), months.end(), m1) - months.begin() + 1) % 12];
            }

        }

        if (m1 == "January" && day1 == 1) {
            year1++;
        }

        w1 = days[(find(days.begin(), days.end(), w1) - days.begin() + 1) % 7];




        if (w1 == w1 && m1 == m2 && day1 == day2 && year1 == year2) {
            break;
        }
    }

    cout << friday13ths << endl;
}
