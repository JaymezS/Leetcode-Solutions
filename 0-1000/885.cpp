#include <bits/stdc++.h>

using namespace std;

int main(){

  class Solution {
  public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
      vector<vector<int>> results;
      results.push_back({rStart, cStart});
      int stepSize = 1;
      int cycle = 0;
      while (results.size() < rows * cols) {
        bool horizontal = cycle % 2 == 0;
        bool negative = stepSize % 2 == 0;
        vector<vector<int>> r = process(rows, cols, rStart, cStart, stepSize, horizontal);
        results.insert(results.end(), r.begin(), r.end());

        if (horizontal) {
          if (negative) {
            cStart -= stepSize;
          } else {
            cStart += stepSize;
          }
        } else {
          if (negative) {
            rStart -= stepSize;
          } else {
            rStart += stepSize;
          }
        }

        cycle++;
        if (cycle == 2) {
          stepSize++;
          cycle = 0;
        }
      }

      return results;
    }


    vector<vector<int>> process(int rows, int cols, int rStart, int cStart, int stepSize, bool horizontal ) {
      vector<vector<int>> res;
      bool negative = stepSize % 2 == 0;
      if (horizontal) { 
        if (rStart < 0 || rStart >= rows) {
          return {};
        }

        if (negative) {
          for (int i = 1; i <= stepSize;i++) {
            if (cStart - i >= 0 && cStart - i < cols) {
              res.push_back({rStart, cStart - i});
            }
          }
        } else {
          for (int i = 1; i <= stepSize;i++) {
            if (cStart + i >= 0 && cStart + i < cols) {
              res.push_back({rStart, cStart + i});
            }
          }
        }
      } else {
        if (cStart < 0 || cStart >= cols) {
          return {};
        }

        if (negative) {
          for (int i = 1; i <= stepSize;i++) {
            if (rStart - i >= 0 && rStart - i < rows) {
              res.push_back({rStart - i, cStart});
            }
          }
        } else {
          for (int i = 1; i <= stepSize;i++) {
            if (rStart + i >= 0 && rStart + i < rows) {
              res.push_back({rStart + i, cStart});
            }
          }
        }
      }

      return res;
    }
  };

  Solution s;
  vector<vector<int>> sol = s.spiralMatrixIII(3, 6, 0, 0);
  for (int i = 0; i < sol.size(); i++) {
    std::cout << sol[i][0] << ", " << sol[i][1] << endl;
  }
    return 0;
}