#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int countSeniors(vector<string>& details) {
      int o = 0;
      for (int i = 0; i < details.size(); i++) {
        int c1 = int(details[i][11]) - 48;
        int c2 = int(details[i][12]) - 48;
        if (c1 * 10 + c2 > 60) {
          o++;
        }
      }

      return o;
    }
  };

  return 0;
}