#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int findMinArrowShots(vector<vector<int>>& points) {
      int n = points.size();
      int c = 0;
      sort(points.begin(), points.end(), less<vector<int>>());
      for (int i = 0; i < n; i++) {
        int m = points[i][1];
        while (i < n) {
          if (points[i][0] <= m) {
            m = min(points[i][1], m);
            i++;
          } else {
            break;
          }
        }
        i--;
        c++;
      }
      return c;
    }
  };
  return 0;
}