#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  int X[4] = {1, 0, -1, 0};
  int Y[4] = {0, 1, 0, -1};

  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int height = grid1.size();
    int width = grid1[0].size();

    int c  = 0;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (grid2[i][j] == 1) {
          bool valid = true;

          queue<pair<int, int>> q;
          q.push({i, j});

          while (q.size()) {
            int ni = q.front().first;
            int nj = q.front().second;
            q.pop();

            if (grid2[ni][nj] == 0) {
              continue;
            }
            grid2[ni][nj] = 0;

            if (grid1[ni][nj] == 0) {
              valid = false;
            }

            for (int k = 0; k < 4; k++) {
              int nxi = ni + X[k];
              int nxj = nj + Y[k];
              if (nxi >= 0 && nxi < height && nxj >= 0 && nxj < width) {
                q.push({nxi, nxj});
              }
            }
          }

          if (valid) {
            c++;
          }
        }
      }
    }

    return c;
  }
};










  return 0;
}