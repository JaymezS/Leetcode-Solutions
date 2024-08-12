#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int trap(vector<int> height) {
      int n = int(height.size());
      int lp = 0;
      int rp = n-1;
      int lmax = 0;
      int rmax = 0;
      int total = 0;

      while (lp <= rp) {
        if (lmax < rmax) {
          lmax = max(height[lp], lmax);
          int x = min(lmax, rmax) - height[lp];
          if (x > 0) {
            total += x;
          }
          lp++;
        } else {
          rmax = max(height[rp], rmax);
          int x = min(lmax, rmax) - height[rp];
          if (x > 0) {
            total += x;
          }
          rp--;
        }
      }

      return total;
    }
  };
  Solution s;
  std::cout << s.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
}