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
          s += processGrid(j, i, grid);
        }
      }

      return s;
    }

    int processGrid(int row, int col, vector<vector<int>> grid) {
      int sum = grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];

      int s2 = grid[row + 2][col] + grid[row + 1][col + 1] + grid[row][col + 2];
      if (s2 != sum) {
        return 0;
      }

      for (int i = 0; i < 3; i++) {
        int s = 0;
        for (int j = 0; j < 3; j++) {
          s += grid[row + i][col + j];
        }
        if (s != sum) {
          return 0;
        }
      }

      for (int i = 0; i < 3; i++) {
        int s = 0;
        for (int j = 0; j < 3; j++) {
          s += grid[row + j][col + i];
        }
        if (s != sum) {
          return 0;
        }
      }

      return 1;
    }
  };

  Solution s;

  std::cout << s.numMagicSquaresInside({{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}});
  return 0;
}