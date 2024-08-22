#include <bits/stdc++.h>

using namespace std;

int main(){



class Solution {
public:
  int findComplement(int num) {
    vector<int> binary;
    while (num >= 1) {
      if (num % 2) {
        binary.push_back(0);
      } else {
        binary.push_back(1);
      }
      num /= 2;
    }

    unsigned int base = 1;
    int total = 0;
    for (int i = 0; i < binary.size(); i++) {
      total += base * binary[i];
      base *= 2;
    }

    return total;
  }


};


Solution s;
s.findComplement(19);









  return 0;
}