#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int numMagicSquaresInside(vector<vector<int>> grid) {
      int width = grid[0].size();
      int height = grid.size();

      if (width < 3 || height < 3) {
        return 0;
      }

      int s = 0;

      for (int i = 0; i < width - 2; i++) {
        for (int j = 0; j < height - 2;j++) {
          s += hasMagicAt(j, i, grid);
        }
      }

      return s;
    }


    int hasMagicAt(int row, int col, vector<vector<int>> grid) {
      if (grid[row + 1][col + 1] == 5) {

        // check uniqueness
        bool used[16] = {false};
        used[0] = true;
        used[10] = true;
        used[11] = true;
        used[12] = true;
        used[13] = true;
        used[14] = true;
        used[15] = true;

        for (int i = row; i < row + 3; i++)
          {
            for (int j = col; j < col + 3; j++)
            {
              if (used[grid[i][j]])
              {
                return 0;
              } else {
              used[grid[i][j]] = true;
            }
          }
        }


        //check diagonal value
        if (grid[row][col] + grid[row + 2][col + 2] != 10) {
          return 0;
        }
        if (grid[row + 2][col] + grid[row][col + 2] != 10) {
          return 0;
        }

        for (int i = row; i < row + 3;i++) {
          int s = 0;
          for (int j = col; j < col + 3;j++) {
            s += grid[i][j];
          }
          if (s != 15) {
            return 0;
          }
        }

        for (int i = col; i < col + 3;i++) {
          int s = 0;
          for (int j = row; j < row + 3;j++) {
            s += grid[j][i];
          }
          if (s != 15) {
            return 0;
          }
        }

        return 1;
      }
      return 0;
    }
  };

  Solution s;

  std::cout << s.numMagicSquaresInside({{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}});
  return 0;
}