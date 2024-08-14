#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(), less<vector<int>>());
      int length = intervals.size();
      vector<vector<int>> res;
      int start = 0;
      int end = 0;
      for (int i = 0; i < length;i++) {
        start = intervals[i][0];
        end = intervals[i][1];
        while (i+1 < length) {
          if (end >= intervals[i+1][0]) {
            end = max(intervals[i + 1][1], end);
            i++;
          } else {
            break;
          }
        }

        res.push_back({start, end});

      }
      return res;
    }
  };

  Solution s;
  vector<vector<int>> v = {{0, 2}, {3, 4}, {2, 5}, {6, 9}};
  vector<vector<int>> x = s.merge(v);
  for (auto& i:x) {
    std::cout << i[0] << i[1] << ", ";
  }
  return 0;
}