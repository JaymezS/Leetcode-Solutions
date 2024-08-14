#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int smallestDistancePair(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end(), less<int>());
      int minD = 0;
      int maxD = nums.back() - nums.front();
      while (minD < maxD) {
        int midD = (minD + maxD) / 2;
        int nLessThen = 0;

        // sliding window
        int left = 0;

        for (int i = 1; i < nums.size();i++) {
          while (nums[i] - nums[left] > midD) {
            left++;
          }
          nLessThen += i - left;
        }


        if (nLessThen < k) {
          minD = midD + 1;
        } else {
          maxD = midD;
        }

      }

      return minD;
    } 
  };

  Solution s;
  vector<int> v = {1, 2, 3, 4, 5};
  std::cout << s.smallestDistancePair(v, 1);
  return 0;
}