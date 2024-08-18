#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  string largestPalindrome(int n, int k) {
    bool isEvenAmt = n % 2 == 0;
    string num(n, '9');
    if (k == 1 || k == 3 || k == 9) {
      return num;
    }
    if (k == 5) {
      num[0] = '5';
      num[num.length() - 1] = '5';
      return num;
    }
    if (k == 2) {
      num[0] = '8';
      num[num.length() - 1] = '8';
      return num;
    }
    
    if (k == 4) {
      num[0] = '8';
      num[num.length() - 1] = '8';
      int x = stoi(num);
      if (x % 4 == 0) {
        return num;
      } else {
        num[1] = '8';
        num[num.length() - 2] = '8';
        return num;
      }
    }


    if (k == 8) {
      if (n <= 6) {
        string s(n, '8');
        return s;
      } else {
        num[0] = '8';
        num[1] = '8';
        num[2] = '8';
        num[num.length() - 2] = '8';
        num[num.length() - 1] = '8';
        num[num.length() - 3] = '8';
      }
    }
    if (k == 6) {

    }
    if (k == 7) {

    }

    return num;
  }
};










  return 0;
}