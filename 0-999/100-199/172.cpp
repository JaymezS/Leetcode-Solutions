#include <bits/stdc++.h>

using namespace std;

int main(){




// brute force simulation -> uint overflow, does not work
class SolutionBrute {
public:
  int trailingZeroes(int n) {
    int c = 0;
    int prod = 1;
    for (int i = n; i > 0; i--) {
      prod *= i;
      while (prod % 10 == 0) {
        prod /= 10;
        c++;
      }
    }
    return c;
  }
};



// observe that only the # of 5 need to be counted, since 10 = 2*5
class SolutionBetter {
public:
  int trailingZeroes(int n) {
    int fiveCount = 0;
    while (n % 5 != 0) {
      n--;
    }

    int powers[5] = {5, 25, 125, 625, 3125};

    for (int i = n; i > 0; i -= 5) {
      for (int j = 4; j >= 0; j--) {
        if (n % powers[j] == 0) {
          fiveCount += j + 1;
          break;
        }
      }
    }

    return fiveCount;
  }
};


// optimize counting fives, skip unnecessary numbers and use binary search to skip powers of 5
class Solution {
public:
  int trailingZeroes(int n) {
    int zeroC = 0;

    for (int i = 5; i <= n; i *= 5) {
      zeroC += floor(n / i);
    }

    return zeroC;
  }
};






  return 0;
}