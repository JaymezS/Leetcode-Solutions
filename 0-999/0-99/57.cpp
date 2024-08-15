#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n = intervals.size();



      if (intervals.size() == 0) {
        return {newInterval};
      }

      int l = 0;
      int r = n-1;
      int mid;
      bool merged = false;
      while (l <= r && !merged) {
        mid = (l + r) / 2;
        if (
          intervals[mid][0] <= newInterval[1] && newInterval[0] <= intervals[mid][1]
        ) {
          merged = true;

          int lexpand = mid;
          int rexpand = mid;
          // binary expand & merge in place
          if (newInterval[1] > intervals[mid][1]) {

            // expand right
            while (rexpand < n) {
              if (intervals[rexpand][0] <= newInterval[1]) {
                rexpand++;
              } else {
                break;
              }
            }
            rexpand--;
            std::cout << rexpand;
          }

          if (newInterval[0] < intervals[mid][0]) {

            while (lexpand >= 0) {
              if (intervals[lexpand][1] >= newInterval[0]) {
                lexpand--;
              } else {
                break;
              }
            }
            lexpand++;
          }
          int ml = min(intervals[lexpand][0], newInterval[0]);
          int mr = max(intervals[rexpand][1], newInterval[1]);

          intervals.erase(intervals.begin() + lexpand, intervals.begin() + rexpand + 1);
          intervals.insert(intervals.begin() + lexpand, {ml, mr});
        } else {
          if (newInterval[0] > intervals[mid][1]) {
            l = mid + 1;
            mid = l;
          } else if (newInterval[1] < intervals[mid][0]) {
            r = mid - 1;
          }
        }
      }

      if (!merged) {
        intervals.insert(intervals.begin() + mid, newInterval);
      }
      return intervals;
    }
  };

  Solution s;
  vector<vector<int>> v = {{4, 5}, {6, 7}, {13, 14}};
  vector<int> nv = {5, 16};
  vector<vector<int>> x = s.insert(v, nv);

  for (auto& i: x) {
    std::cout << i[0] << ", " << i[1] << endl;
  }
  return 0;
}