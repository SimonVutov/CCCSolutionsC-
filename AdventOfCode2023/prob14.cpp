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

void move(vector<string> &v, int x, int y) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].length(); j++) {
      if (v[i][j] == 'O') {
        if (y == 1) {
          // move up as far as possible (in negetive y)
          int atY = i;
          while (atY - 1 >= 0 && v[atY - 1][j] != '#') {
            atY--;
          }
          while (atY < n && v[atY][j] != '.' && atY < i) {
            atY++;
          }
          if (i != atY && v[atY][j] == '.') {
            v[i][j] = '.';
            v[atY][j] = 'O';
          }
        }
        if (y == -1) {
          // move down as far as possible
          int atY = i;
          while (atY + 1 < n && v[atY + 1][j] != '#') {
            atY++;
          }
          while (atY >= 0 && v[atY][j] != '.' && atY > i) {
            atY--;
          }
          if (i != atY && v[atY][j] == '.') {
            v[i][j] = '.';
            v[atY][j] = 'O';
          }
        }
        if (x == 1) {
          // move right as far as possible (in positive x)
          int atX = j;
          while (atX + 1 < v[i].length() && v[i][atX + 1] != '#') {
            atX++;
          }
          while (atX >= 0 && v[i][atX] != '.' && atX > j) {
            atX--;
          }
          if (j != atX && v[i][atX] == '.') {
            v[i][j] = '.';
            v[i][atX] = 'O';
          }
        }
        if (x == -1) {
          // move left as far as possible
          int atX = j;
          while (atX - 1 >= 0 && v[i][atX - 1] != '#') {
            atX--;
          }
          while (atX < v[i].length() && v[i][atX] != '.' && atX < j) {
            atX++;
          }
          if (j != atX && v[i][atX] == '.') {
            v[i][j] = '.';
            v[i][atX] = 'O';
          }
        }
      }
    }
  }
}

int readWeight(vector<string> v) {
  int t = 0;
  int n = v.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].length(); j++) {
      if (v[i][j] == 'O') {
        t += n - i;
      }
    }
  }
  cout << t << endl;
  return t;
}

void pri(vector<string> v) {
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
}

void cycle(vector<string> &v) {
  move(v, 0, 1);
  move(v, -1, 0);
  move(v, 0, -1);
  move(v, 1, 0);
}

int main() {
  string line;
  ifstream myfile("t1.txt");
  vector<string> v;

  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      istringstream iss(line);
      v.push_back(line);
    }
  } else
    cout << "Unable to open file";
  myfile.close();

  ofstream outputFile("output.txt"); // Open a file for writing

  if (!outputFile.is_open()) { // Check if the file is successfully opened
    cerr << "Error opening the file!" << endl;
    return 1; // return an error code
  }

  for (int i = 0; i < 100000; i++) {
    cycle(v);
    // pri(v);
    cout << i << " ";
    outputFile << i << " " << readWeight(v) << endl;
  }

  return 0;
}