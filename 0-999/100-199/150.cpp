#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
      vector<int> nums;

      int t;
      for (auto& i: tokens) {
        if (i == "+") {
          nums[nums.size() - 2] += nums.back();
          nums.pop_back();
        } else if (i == "-") {
          nums[nums.size() - 2] -= nums.back();
          nums.pop_back();
        } else if (i == "*") {
          nums[nums.size() - 2] *= nums.back();
          nums.pop_back();
        } else if (i == "/") {
          nums[nums.size() - 2] /= nums.back();
          nums.pop_back();
        } else {
          int x = stoi(i);
          nums.push_back(x);
        }
      }
      return nums[0];
    }
  };
  return 0;
}