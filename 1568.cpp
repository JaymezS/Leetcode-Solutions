#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int minDays(vector<vector<int>> grid) {
      int height = grid.size();
      int width = grid[0].size();
      vector<vector<bool>> visited(height, vector<bool>(width, false));
      bool connect1 = false;
      bool solved = false;
      for (int i = 0; i < height; i++) {
        if (solved) {
          break;
        }
        for (int j = 0; j < width; j++) {
          if (solved) {
            break;
          }
          if (grid[i][j] == 1) {
            queue<pair<int, int>> q;
            q.push({i, j});

            while (q.size()) {
              int x = q.front().first;
              int y = q.front().second;
              q.pop();

              visited[x][y] = true;
              int c = 0;
              if (x - 1 >= 0) {
                if (grid[x - 1][y]){
                  if(!visited[x-1][y]) {
                    q.push({x-1, y});
                  }
                  c++;
                } 
              }
              if (x + 1 < height) {
                if (grid[x + 1][y]){
                  if(!visited[x+1][y]) {
                    q.push({x+1, y});
                  }
                  c++;
                } 
              }
              if (y - 1 >= 0) {
                if (grid[x][y - 1]) {
                  if (!visited[x][y - 1]) {
                    q.push({x, y - 1});
                  }
                  c++;
                } 
              } 
              if (y + 1 < width) {
                if (grid[x][y + 1]) {
                  if (!visited[x][y + 1]) {
                    q.push({x, y + 1});
                  }
                  c++;
                } 
              }
              if (c == 1) {
                connect1 = true;
              }
            }

            solved = true;
          }
        }
      }

      

      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          if (grid[i][j] == 1 && visited[i][j] == 0) {
            return 0;
          }
        }
      }

      if (connect1) {
        if (height ==2 && width == 1) {
          if (grid[0][0] == 1 && grid[1][0] == 1) {
            return 2;
          }
        }

        if (height ==1 && width == 2) {
          if (grid[0][0] == 1 && grid[0][1] == 1) {
            return 2;
          }
        }

        return 1;
      }
      return 2;
    }
  };

  Solution s;
  std::cout << s.minDays({{0, 1, 0, 1}});
  return 0;
}