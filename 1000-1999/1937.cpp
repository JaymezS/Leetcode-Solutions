#include <bits/stdc++.h>

using namespace std;

int main(){


// Brute Force Solution O(n^3) TLE
class SolutionBrute {
public:
  long long maxPoints(vector<vector<int>>& points) {
    int width = points[0].size();
    int height = points.size();
    vector<vector<long long>> table(height, vector<long long>(width, 0));

    for (int i = 0; i < width; i++) {
      table[0][i] = points[0][i];
    }



    for (int i = 1; i < height; i++) {
      for (int j = 0; j < width; j++)
      {
        table[i][j] = points[i][j];
        for (int k = 0; k < width; k++)
        {
          if (points[i][j] + table[i - 1][k] - abs(k - j) > table[i][j])
          {
            table[i][j] = points[i][j] + table[i - 1][k] - abs(k - j);
          }
        }
      }
    }

    long long t = 0;
    for (int i = 0; i < width; i++) {
      if (table.back()[i] > t) {
        t = table.back()[i];
      }
    }
    return t;
  }
};







// Anti-intuitive approach
class Solution {
public:
  long long maxPoints(vector<vector<int>>& points) {
    int width = points[0].size();
    int height = points.size();

    vector<long long> last(width), curr(width);
    
    for (int i = 0; i < width; i++) {
      last[i] = points[0][i];
      curr[i] = points[0][i];
    }


    for (int i = 1; i < height; i++) {        
      long long tm = 0;
      for (int j = 0; j < width; j++) {
        tm = max(tm - 1, last[j]);
        curr[j] = tm;
      }
      tm = 0;
      for (int j = width - 1; j >= 0; j--) {
        tm = max(tm - 1, last[j]);
        curr[j] = max(curr[j], tm) + points[i][j];
      }
      last = curr;
    }

    return *max_element(curr.begin(), curr.end());
  }
};








  return 0;
}