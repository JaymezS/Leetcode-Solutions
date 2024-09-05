#include <bits/stdc++.h>


using namespace std;


int main() {



class Solution {
public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int xPos = 0;
    int yPos = 0;
    int dir = 0;
    int xDir[4] = {0, 1, 0, -1};
    int yDir[4] = {1, 0, -1, 0};

    int maxV = 0;
    unordered_map<int, vector<int>> table;
    for (auto& v: obstacles) {
      if (table.count(v[0])) {
        table[v[0]].push_back(v[1]);
      } else {
        table[v[0]] = {v[1]};
      }
    }

    for (auto& command: commands) {
      if (command == -2) {
        dir -= 1;
        if (dir < 0) {
          dir = 3;
        }
      } else if (command == -1) {
        dir += 1;
        if (dir > 3) {
          dir = 0;
        }
      } else {
        for (int i = 0; i < command; i++) {
          bool canCont = true;
          for (auto& objY: table[xPos + xDir[dir]]) {
            if (objY == yPos + yDir[dir]) {
              canCont = false;
              break;
            }
          }

          if (canCont) {
            xPos += xDir[dir];
            yPos += yDir[dir];
          } else {
            continue;
          }
        }
      }

      
      maxV = max(int(pow(xPos, 2)) + int(pow(yPos, 2)), maxV);
    }

    return maxV;
  }
};





  return 0;
}