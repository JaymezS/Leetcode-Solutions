#include <bits/stdc++.h>

using namespace std;

int main(){




class Solution {
public:
  vector<int> resultsArray(vector<int>& nums, int k) {
    if (k == 1) {
      return nums;
    }

    int length = nums.size();
    vector<int> results;
    int lastConsecutiveIndex = length - 1;
    int consecutiveCounter = 1;
    for (int index = length - 2; index >= 0; index--) {
      if (nums[index] == nums[index+1] - 1) {
        consecutiveCounter++;
      } else {
        consecutiveCounter = 1;
        lastConsecutiveIndex = index;
      }
      if (lastConsecutiveIndex - index + 1 >= k) {
        results.push_back(nums[index + k - 1]);
      } else {
        if (length - index >= k) {
          results.push_back(-1);
        }
      }

    }

    reverse(results.begin(), results.end());

    return results;
  }
};











  return 0;
}