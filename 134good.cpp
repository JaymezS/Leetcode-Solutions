#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int canCompleteCircuit(vector<int> gas, vector<int> cost) {
      int n = gas.size();

      int start = 0;
      int penalty = 0;
      int currentGas = 0;
      for (int i = 0; i < n;i++) {
        currentGas += gas[i] - cost[i];
        if (currentGas < 0) {
          penalty -= currentGas;
          currentGas = 0;
          start = i + 1 % n;
        }
      }

      if ((currentGas - penalty) >= 0) {
        return start;
      }

      return -1;
    }
  };

  Solution s;
  std::cout << s.canCompleteCircuit({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2});
  return 0;
}