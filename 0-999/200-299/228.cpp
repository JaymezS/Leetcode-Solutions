#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {

      if (nums.size() == 0) {
        return {};
      }

      vector<string> res = {};
      int prev = nums[0];
      int curr = nums[0];
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - 1 != curr) {
          if (prev == curr) {
            res.push_back(to_string(prev));
          } else {
            res.push_back(to_string(prev) + "->" + to_string(curr));
          }
          prev = nums[i];
        }
        curr = nums[i];
      }

      if (prev == curr) {
        res.push_back(to_string(prev));
      } else {
        res.push_back(to_string(prev) + "->" + to_string(curr));
      }
      return res;
    }
  };
  return 0;
}