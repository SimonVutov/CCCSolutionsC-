#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int num(string main, int i) {
  string nums[9] = {"one", "two",   "three", "four", "five",
                    "six", "seven", "eight", "nine"};

  for (int j = 0; j < 9; j++) {
    if (i + nums[j].length() <= main.length()) {
      if (main.substr(i, nums[j].length()) == nums[j]) {
        return j + 1;
      }
    }
  }
  return -1;
}
int main() {
  string line;
  double ans = 0;
  ifstream myfile("t1.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {

      int lastDig = 0;
      int firstDig = -1;
      for (int i = 0; i < line.length(); i++) {
        int number = num(line, i);
        if (number == -1) {
          if (line[i] - '0' >= 0 && line[i] - '0' <= 9)
            number = line[i] - '0';
        }
        if (number != -1) {
          if (firstDig == -1)
            firstDig = number;
          lastDig = number;
        }
      }
      ans += firstDig * 10 + lastDig;

      cout << line << " " << firstDig << " " << lastDig << endl;
    }
  } else
    cout << "Unable to open file";
  myfile.close();
  cout << ans << endl;

  return 0;
}