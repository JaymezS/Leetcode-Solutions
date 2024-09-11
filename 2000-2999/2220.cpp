#include <bits/stdc++.h>


using namespace std;


int main() {




class Solution {
public:
  int minBitFlips(int start, int goal) {
    vector<int> sb(32, 0);
    int c = 0;

    int counter = 31;
    while (start > 0) {
      if (start % 2) {
        sb[counter] = 1;
      } else {
        sb[counter] = 0;
      }

      counter--;
      start /= 2;
    }

    counter = 31;
    while (goal > 0) {
      if ((goal % 2) != sb[counter]) {
        c++;
      }

      counter--;
      goal /= 2;
    }
    for (int i = counter; i >= 0; i--) {
      if (sb[i] == 1) {
        c++;
      }
    }

    return c;
  }
};




  return 0;
}