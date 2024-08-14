#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      unordered_map<int, int> dict;
      for (int i = 0; i < nums.size(); i++) {
        if (!dict.count(nums[i])) {
          dict[nums[i]] = i;
        } else {
          if (i - dict[nums[i]] <= k) {
            return true;
          }
          dict[nums[i]] = i;
        }
      }
      return false;
    }
  };

  
  return 0;
}