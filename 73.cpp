#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    void setZeroes(vector<vector<int>>& matrix) {
      int width = matrix[0].size();
      int height = matrix.size();
      vector<int> x(width, 1);
      vector<int> y(height, 1);

      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          if (matrix[i][j] == 0) {
            x[j] = 0;
            y[i] = 0;
          }
        }
      }
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          if (x[j] == 0 || y[i] == 0) {
            matrix[i][j] = 0;
          }
        }
      }
    }
  };
  return 0;
}