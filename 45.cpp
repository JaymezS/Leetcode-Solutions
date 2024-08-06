#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int jump(vector<int> nums) {
      int n = nums.size();

      if (n == 1) {
        return 0;
      }
      if (nums[0] >= n - 1) {
        return 1;
      }
      int pos = 0;
      int j = 0;

      while (true) {
        int max = 0;
        int max_i = pos;
        for (int i = pos + 1; i < pos + nums[pos] + 1; i++) {
          int r = nums[i] + i;
          if (r > max) {
            if (r >= n - 1) {
              j += 2;
              return j;
            }
            max = r;
            max_i = i;
          }
        }
        pos = max_i;
        j++;
      }
    }
  };

  Solution s;
  cout << s.jump({2, 3, 0, 1, 4});
  return 0;
}