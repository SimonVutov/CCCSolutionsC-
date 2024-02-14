#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    int currentHour = 12;
    int currentMinute = 0;

    int res = 0;

    int days = n / 1440;
    n = n % 1440;
    res += days * 62;

    for (int i = 0; i <= n; i++) {
        int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
        if (currentHour < 10) {
            num1 = 0;
            num2 = currentHour;
        } else {
            num1 = currentHour / 10;
            num2 = currentHour % 10;
        }
        if (currentMinute < 10) {
            num3 = 0;
            num4 = currentMinute;
        } else {
            num3 = currentMinute / 10;
            num4 = currentMinute % 10;
        }

        if (num1 != 0) {
            if (num1 - num2 == num2 - num3 && num2 - num3 == num3 - num4) {
                res++;
            }
        } else {
            if (num2 - num3 == num3 - num4) {
                res++;
            }
        }

        currentMinute++;
        if (currentMinute == 60) {
            currentMinute = 0;
            currentHour++;
            if (currentHour == 13) {
                currentHour = 1;
            }
        }
    }

    cout << res << endl;
}
