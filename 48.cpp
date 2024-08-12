#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    void rotate(vector<vector<int>>& matrix) {
      int n = matrix.size() - 1;
      int t;
      // flip across diagonal: top left -> bottom right...
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
          t = matrix[i][j];
          matrix[i][j] = matrix[n - j][n - i];
          matrix[n - j][n - i] = t;
        }
      }

      n++;

      for (int i = 0; i < n/2; i++) {
        for (int x = 0; x < n; x++) {
          t = matrix[i][x];
          matrix[i][x] = matrix[n - 1 - i][x];
          matrix[n - 1 - i][x] = t;
        }
      }
    }
  };
  return 0;
}
