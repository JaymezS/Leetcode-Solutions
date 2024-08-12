#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    string convert(string s, int numRows) {
      if (numRows == 1) {
        return s;
      }


      string res = "";
      int n = s.length();
      int sectionLength = (numRows - 1) * 2;

      int stnl = 0;
      while (stnl < n) {
        res += s[stnl];
        stnl += sectionLength;
      }


      int segLength = (numRows - 2);
      int currentSeg = 1;
      for (int i = currentSeg; i < 1 + segLength;i++) {
        int stn = i;
        int step = 0;
        while (stn < n) {
          res += s[stn];
          if (stn % sectionLength == i) {
            step++;
            stn = step * sectionLength - i;
          } else {
            stn = step * sectionLength + i;
          }
        }
      }

      stnl = numRows - 1;
      while (stnl < n) {
        res += s[stnl];
        stnl += sectionLength;
      }

      return res;
    }
  };

  Solution s;
  std::cout << s.convert("PAYPALISHIRING", 3);
  return 0;
}
