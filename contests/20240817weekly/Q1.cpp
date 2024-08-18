#include <bits/stdc++.h>

using namespace std;

int main(){


class Solution {
public:
  int countKConstraintSubstrings(string s, int k) {
    int length = s.length();
    int c = 0;
    for (int i = 0; i < length; i++) {
      int oneC = 0;
      int zeroC = 0;
      int counter = 0;
      for (int j = i; j < length; j++) {
        if (s[j] == '0') {
          zeroC++;
        } else {
          oneC++;
        }

        if (oneC > k && zeroC > k) {
          break;
        }
        counter++;
      }
      c += counter;
    }

    return c;
  }
};













  return 0;
}