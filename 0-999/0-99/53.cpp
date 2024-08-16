#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int am = INT_MIN;
    int cm = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > cm) {
        if (cm < 0) {
          cm = nums[i];
        } else {
          cm += nums[i];
        }
      } else {
        cm += nums[i];
      }
      am = max(am, cm);
    }

    return am;
  }
};










  return 0;
}