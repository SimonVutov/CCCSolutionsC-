#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int longestDist(vector<vector<bool>> &vis, vector<string> &grid, int x = 0,
                int y = 0, int curDist = 0) {
  int maxVal = 0;

  // Base case
  if (x < 0 || x >= vis[0].size() || y < 0 || y >= vis.size())
    return 0;
  if (vis[x][y] == true)
    return 0;
  vis[x][y] = true;
  if (grid[x][y] == '#')
    return 0;
  if (x == vis[0].size() - 1 && y == vis.size() - 1)
    return curDist;

  // Recursive case
  if (grid[x][y] == '>' || grid[x][y] == '.')
    maxVal = max(maxVal, longestDist(vis, grid, x, y + 1, curDist + 1));
  if (grid[x][y] == '<' || grid[x][y] == '.')
    maxVal = max(maxVal, longestDist(vis, grid, x, y - 1, curDist + 1));
  if (grid[x][y] == 'v' || grid[x][y] == '.')
    maxVal = max(maxVal, longestDist(vis, grid, x - 1, y, curDist + 1));
  if (grid[x][y] == '^' || grid[x][y] == '.')
    maxVal = max(maxVal, longestDist(vis, grid, x + 1, y, curDist + 1));

  vis[x][y] = false;

  return maxVal;
}

int main() {
  string line;
  ifstream myfile("t23.txt");
  vector<string> v;

  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      istringstream iss(line);
      v.push_back(line);
    }
  } else
    cout << "Unable to open file";
  myfile.close();

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }

  vector<vector<bool>> visited(v.size(), vector<bool>(v[0].size(), false));

  cout << longestDist(visited, v);

  return 0;
}