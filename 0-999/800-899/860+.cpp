#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    bool lemonadeChange(vector<int>& bills) {
      int f = 0;
      int t = 0;
      for (auto& i: bills) {
        if (i == 5) {
          f++;
        } else if (i == 10) {
          t++;
          f--;
          if (f < 0) {
            return false;
          }
        } else {
          if (t > 0) {
            if (f > 0) {
              t--;
              f--;
            } else {
              return false;
            }
          } else {
            if (f >= 3) {
              f -= 3;
            } else {
              return false;
            }
          }
        }
      }
      return true;
    }
  };
  return 0;
}
