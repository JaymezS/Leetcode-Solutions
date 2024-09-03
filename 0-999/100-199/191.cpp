#include <bits/stdc++.h>


using namespace std;


int main() {



class Solution {
public:
  int hammingWeight(int n) {
    int c = 0;
    while (n > 0) {
      while (n % 2 == 0) {
        n /= 2;
      }   
      n -= 1;
      c++;
    }

    return c;
  }
};





  return 0;
}