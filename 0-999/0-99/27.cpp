#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int p1 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[p1] = nums[i];
        p1++;
      }
    }
    return p1;
  }
};










  return 0;
}