#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    bool lemonadeChange(vector<int>& bills) {
      int b[3] = {0, 0, 0};
      for (int i = 0; i < bills.size(); i++) {
        if (bills[i] == 5) {
          b[0]++;
        } else if (bills[i] == 10) {
          b[1]++;
          b[0]--;
          if (b[0] < 0) {
            return false;
          }
        } else {
          b[2]++;
          if (b[1] > 0) {
            if (b[0] > 0) {
              b[1]--;
              b[0]--;
            } else {
              return false;
            }
          } else {
            if (b[0] >= 3) {
              b[0] -= 3;
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
