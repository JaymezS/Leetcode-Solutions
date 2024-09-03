#include <bits/stdc++.h>


using namespace std;


int main() {




class Solution {
public:
  string addBinary(string a, string b) {
    int al = a.length();
    int bl = b.length();
    int remainder = 0;
    int sum = 0;
    string res = "";

    for (int i = 0; i < min(al, bl); i++) {
      sum = (a[al - i - 1] - '0') + (b[bl - 1 - i] - '0') + remainder;

      if (sum % 2) {
        res = "1" + res;
      } else {
        res = "0" + res;
      }

      if (sum >= 2) {
        remainder = 1;
      } else {
        remainder = 0;
      }
    }   

    if (al > bl) {
      for (int i = 0; i < al - bl; i++) {
        sum = (a[al - bl -  i - 1] - '0') + remainder;

        if (sum % 2) {
          res = "1" + res;
        } else {
          res = "0" + res;
        }

        if (sum >= 2) {
          remainder = 1;
        } else {
          remainder = 0;
        }
      }
    } else {
      for (int i = 0; i < bl - al; i++) {
        sum = (b[bl - al - i - 1] - '0') + remainder;

        if (sum % 2) {
          res = "1" + res;
        } else {
          res = "0" + res;
        }

        if (sum >= 2) {
          remainder = 1;
        } else {
          remainder = 0;
        }
      }
    }
    if (remainder) {
      return "1" + res;
    }
    return res;
  }
};




  return 0;
}