#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int canCompleteCircuit(vector<int> gas, vector<int> cost) {
      int n = gas.size();

      for (int i = 0; i < n; i++) {
        if (gas[i] - cost[i] < 0) {
          continue;
        }

        int g = 0;
        bool good = true;
        for (int j = 0; j < n; j++) {
          g += gas[(i + j) % n] - cost[(i + j) % n];
          if (g < 0) {
            good = false;
            break;
          }
        }
        if (good) {
          return i;
        }
      }

      return -1;
    }
  };

  Solution s;
  cout << s.canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2});
  return 0;
}