#include <bits/stdc++.h>

using namespace std;

int main(){


// bad idea



class Solution {
public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    if (k == 1) {
      return nums;
    }

    int length = nums.size();
    int startingNumber = nums[0];
    int expected;
    vector<int> results;

    bool isConsecutive = true;
    int lastConsecutiveIndex = 0;
    int actual = startingNumber;
    for (int i = 1; i < k;i++) {
      actual += nums[i];
      if (nums[i] != nums[i-1] + 1) {
        isConsecutive = false;
      }
    }

    

    for (int i = k; i < length + 1; i++) {
      startingNumber = nums[i - k];
      expected = (2 * startingNumber + (k - 1)) * k / 2;
      if (actual != expected) {
        results.push_back(-1);
      } else {
        results.push_back(startingNumber + k - 1);
      }
      if (i < length) {
        actual += nums[i];
        actual -= nums[i - k];
      } else {
        break;
      }
    }
    return results;
  }
};











  return 0;
}