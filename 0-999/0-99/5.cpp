#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n == 1) {
      return s;
    }
    int mp1 = 0;
    int mp2 = 0;
    int sgp = 0;
    int dbp = 0;

    for (int i = 1; i < n;i++) {
      sgp = 0;
      dbp = 0;
      while (i - sgp >= 0 && i + sgp < n) {
        if (s[i-sgp] == s[i+sgp]) {
          sgp++;
        } else {
          break;
        }
      }

      if (s[i] == s[i-1]) {
        while (i-dbp-1 >= 0 && i + dbp < n) {
          if (s[i-1-dbp] == s[i+dbp]) {
            dbp++;
          } else {
            break;
          }
        }
      }
      // p1 p2 are 1 unit larger
      if ((i+sgp) - (i-sgp) > mp2 - mp1) {
        mp2 = i + sgp;
        mp1 = i - sgp;
      } 
      if ((i+dbp) - (i - 1 - dbp) > mp2 - mp1) {
        mp2 = i + dbp;
        mp1 = i - dbp - 1;
      }

    }

    return s.substr(mp1 + 1, mp2 - mp1 - 1);
  }
};

Solution s;
std::cout << s.longestPalindrome("abcbaca");

return 0;
}