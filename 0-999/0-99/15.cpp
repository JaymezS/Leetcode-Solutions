#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end(), less<int>());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 2; i++) {
      int p1 = i + 1;
      int p2 = nums.size() - 1;
      while (p1 < p2) {
        int n = nums[p1] + nums[p2] + nums[i];
        if (n == 0) {
          if (p1 == i + 1 || p2 == nums.size() - 1) {
                res.push_back({nums[i], nums[p1], nums[p2]});

            }
        }
        if (n <= 0) {
          p1++;
        } else {
          p2--;
        }
      }
    }
    return res;
  }
};










  return 0;
}