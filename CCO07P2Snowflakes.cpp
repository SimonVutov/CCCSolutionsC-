#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  unordered_map<string, int> snowflakes;
  for (int i = 0; i < n; i++) {
    vector<int> snowflake(6);
    int min = 1000000000;
    for (int j = 0; j < 6; j++) {
      cin >> snowflake[j];
      min = min(min, snowflake[j]);
    }
    if (snowflake[0] == min && snowflake[1] == min && snowflake[2] == min &&
        snowflake[3] == min && snowflake[4] == min && snowflake[5] == min) {
      cout << 1 << endl;
    } else {
      while (snowflake[0] != min && snowflake[1] != min) {
        snowflake.push_back(snowflake[0]);
        snowflake.erase(snowflake.begin());
      }
    }
    string s = "";
    for (int j = 0; j < 6; j++)
      s += to_string(snowflake[j]) + ",";
    snowflakes[s]++;
    if (snowflakes[s] == 2) {
      cout << "true" << endl;
      return 0;
    }
  }
  cout << "false" << endl;
}