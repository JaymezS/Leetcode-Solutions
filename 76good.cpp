#include <bits/stdc++.h>

using namespace std;

int main(){
class Solution {
public:
    string minWindow(string s, string t) {
      if (t.length() > s.length()) {
        return "";
      }

      long requiredCharDict[128] = {0};
      bool requiredCharBool[128] = {false};

      for (int i = 0; i < t.length(); i++) {
        requiredCharDict[int(t[i])]++;
        requiredCharBool[int(t[i])] = true;
      }

      
      int startIndex = -1;
      int min = s.length();

      int p1 = 0;
      int p2 = 0;
      int unfulfilled = t.length();
      while (p2 < s.length()) {
        if (unfulfilled == 0) {
          if (p2 - p1 < min) {
            startIndex = p1;
            min = p2 - p1;
          }
          if (requiredCharBool[int(s[p1])]) {
            requiredCharDict[int(s[p1])]++;
            if (requiredCharDict[int(s[p1])] > 0) {
              unfulfilled++;
            }
          }

          p1++;
        } else {

          if (requiredCharBool[int(s[p2])]) {
            requiredCharDict[s[p2]]--;
            if (requiredCharDict[s[p2]] >= 0) {
              unfulfilled--;
            }
          }


          p2++;
        }
      }


      if (unfulfilled == 0) {
        while (p1 < p2 && unfulfilled == 0) {
          if (p2 - p1 <= min) {
            startIndex = p1;
            min = p2 - p1;
          }

          if (requiredCharBool[int(s[p1])]) {
            requiredCharDict[int(s[p1])]++;
            if (requiredCharDict[int(s[p1])] > 0) {
              break;
            }
          }

          p1++;
        }
      }

      if (startIndex == -1) {
        return "";
      }
      return s.substr(startIndex, min);
    }
};
Solution s;
std::cout << s.minWindow("ADOBECODEBANC", "ABC");
return 0;
}