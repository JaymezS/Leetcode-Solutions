#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      int width = matrix[0].size();
      int height = matrix.size();

      bool colHasZero = false;
      bool rowHasZero = false;
      int i;
      int j;

      for (i = 0; i < width; i++) {
        if (matrix[0][i] == 0) {
          rowHasZero = true;
        }
      }

      for (i = 0; i < height; i++) {
        if (matrix[i][0] == 0) {
          colHasZero = true;
        }
      }

      for (i = 1; i < height; i++) {
        for (j = 1; j < width; j++) {
          if (matrix[i][j] == 0) {
            matrix[i][0] = 0;
            matrix[0][j] = 0;
          }
        }
      }


      for (i = 1; i < height; i++) {
        for (j = 1; j < width; j++) {
          if (matrix[0][j] == 0 || matrix[i][0] == 0) {
            matrix[i][j] = 0;
          }
        }
      }

      if (colHasZero) {
        for (i = 0; i < height; i++) {
          matrix[i][0] = 0;
        }
      }

      if (rowHasZero) {
        for (i = 0; i < width; i++) {
          matrix[0][i] = 0;
        }
      }
    }
  };
  return 0;
}