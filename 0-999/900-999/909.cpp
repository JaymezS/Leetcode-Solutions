#include <bits/stdc++.h>

using namespace std;

int main(){




class Solution {
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int length = board.size();
    int target = length * length;
    queue<pair<int, int>> q;
    set<int> visited;
    q.push({1, 0});

    while (q.size()) {
      int location = q.front().first;
      int depth = q.front().second;
      q.pop();
      if (visited.count(location)) {
        continue;
      }
      visited.insert(location);

      if (location == target) {
        return depth;
      }

      for (int i = 1; i < 7; i++) {
        int newLocation = location + i;
        if (newLocation > target) {
          break;
        }
        int y = length - 1 - (newLocation - 1) / length;
        int x = (newLocation - 1) % length;

        if ((length - 1 - y) % 2) {
          x = length - 1 - x;
        }
        if (board[y][x] == -1) {
          q.push({newLocation, depth + 1});
        } else {
          q.push({board[y][x], depth + 1});
        }
      }
    }
    return -1;
  }
};











  return 0;
}