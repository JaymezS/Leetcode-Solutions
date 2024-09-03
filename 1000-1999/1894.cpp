#include <bits/stdc++.h>


using namespace std;


int main() {




class Solution {
public:
  int chalkReplacer(vector<int>& chalk, int k) {
    int sum = 0;
    for (auto& c: chalk) {
      sum += c;
    }

    while (k >= sum) {
      k -= sum;
    }

    for (int i = 0; i < chalk.size(); i++) {
      if (k < chalk[i]) {
        return i;
      }
      k -= chalk[i];
    }

    return -1;
  }
};




  return 0;
}