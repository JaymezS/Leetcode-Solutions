#include <bits/stdc++.h>


using namespace std;


int main() {



class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> maxMoney(nums.size(), 0);
    maxMoney[0] = nums[0];

    maxMoney[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      maxMoney[i] = max(nums[i] + maxMoney[i-2], maxMoney[i-1]);
    }
    return maxMoney.back();
  }
};





  return 0;
}