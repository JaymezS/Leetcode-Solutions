#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int, bool> d;
      for (auto& n: nums) {
        d[n] = true;
      }
      int m = 0;
      for (auto& n: nums) {
        if (d[n]) {
          int l = 0;
          while (d.count(n)) {
            d[n] = false;
            l++;
            n -= 1;
          }

          n += l;
          while (d.count(n)) {
            d[n] = false;
            l++;
            n += 1;
          }

          m = max(l - 1, m);
        }
      }
      return m;
    }
  };
  
  return 0;
}