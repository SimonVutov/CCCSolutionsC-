#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

bool is_number(const std::string &s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it))
    ++it;
  return !s.empty() && it == s.end();
}

int main() {
  string line;
  double ans = 0;
  double powSum = 0;
  double totalIDSum = 0;
  ifstream myfile("t1.txt");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      istringstream iss(line);
      vector<string> tokens;
      string token;

      while (iss >> token) {
        tokens.push_back(token);
      }

      int gameID = -1;

      int minR = -1, minG = -1, minB = -1;

      int lastNum = 0;
      for (int i = 0; i < tokens.size(); i++) {
        if (is_number(tokens[i].substr(0, tokens[i].length() - 1)) &&
            gameID == -1)
          gameID = stoi(tokens[i].substr(0, tokens[i].length() - 1));
        if (is_number(tokens[i])) {
          lastNum = stoi(tokens[i]);
        } else {

          string x = tokens[i];
          if (x[x.length() - 1] == ',' || x[x.length() - 1] == ';')
            x = tokens[i].substr(0, tokens[i].length() - 1);
          if (x == "red") {
            if (lastNum > 0) {
              ans += gameID;
              minR = max(minR, lastNum);
              cout << gameID << " lastNum " << minR << " red " << endl;
            }
          } else if (x == "green") {
            if (lastNum > 0) {
              ans += gameID;
              minG = max(minG, lastNum);
              cout << gameID << " lastNum " << minG << " green " << endl;
            }
          } else if (x == "blue") {
            if (lastNum > 0) {
              ans += gameID;
              minB = max(minB, lastNum);
              cout << gameID << " lastNum " << minB << " blue " << endl;
            }
          }
        }
      }
      if (minR == -1)
        minR = 0;
      if (minG == -1)
        minG = 0;
      if (minB == -1)
        minB = 0;
      powSum += minR * minG * minB;
      totalIDSum += gameID;
    }
  } else
    cout << "Unable to open file";
  myfile.close();
  cout << powSum << endl;

  return 0;
}