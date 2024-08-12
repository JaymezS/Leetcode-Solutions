#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

      int multiplier[4] = {1, 1, -1, -1};

      int width = matrix[0].size();
      int height = matrix.size();

      vector<int> results(width * height);

      int cycle = 0;
      int curr = 0;
      int heightLength = height - 1;
      int widthLength = width;

      int tx = -1;
      int ty = 0;

      while (heightLength > -1 && widthLength > -1) {
        if (cycle % 2) {
          // move vertical
          for (int i = 0; i < heightLength; i++) {
            ty += multiplier[cycle % 4];
            results[curr] = matrix[ty][tx];
            curr++;
          }
          heightLength--;
        } else {
          // move horizontal
          for (int i = 0; i < widthLength; i++) {
            tx += multiplier[cycle % 4];
            results[curr] = matrix[ty][tx];
            curr++;
          }
          widthLength--;
        }
        cycle++;
      }

      return results;
    }
  };

  Solution s;
  vector<vector<int>> m = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> res = s.spiralOrder(m);
  for (int i = 0; i < res.size(); i++) {
    std::cout << res[i] << ", ";
  }
  return 0;
}
