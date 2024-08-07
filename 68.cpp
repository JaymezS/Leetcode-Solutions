#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      vector<string> results;
      int n = words.size();

      vector<string> curr;
      curr.push_back(words[0]);
      int l = words[0].length();
      for (int i = 1; i < n;i++) {
        if (l + words[i].length() + 1 > maxWidth) {
          results.push_back(justifyGroup(curr, maxWidth));
          curr.clear();
          curr.push_back(words[i]);
          l = words[i].length();
        } else {
          l = l + words[i].length() + 1;
          curr.push_back(words[i]);
        }
      }
      if (curr.size()) {
        results.push_back(justifyGroup(curr, maxWidth, true));
      }

      return results;
    }


    string justifyGroup(vector<string> words, int width, bool last = false) {
      int n = words.size();
      if (last) {
        string res = words[0];
        for (int i = 1; i < n;i++) {
          res += " " + words[i];
        }
        string s(width - res.length(), ' ');
        return res + s;
      }


      string res = words[0];
      if (n == 1) {
        string s(width - words[0].length(), ' ');
        return words[0] + s;
      }
      int spaceLocations = n - 1;
      int usableSpaces = width;
      for (int i = 0; i < n;i++) {
        usableSpaces -= words[i].length();
      }

      for (int i = 1; i < n;i++) {
        int nSpace = 0;
        if (usableSpaces % spaceLocations) {
          nSpace = floor(usableSpaces / spaceLocations) + 1;
        } else {
          nSpace = usableSpaces / spaceLocations;
        }
        string s(nSpace, ' ');
        res += s + words[i];
        usableSpaces -= nSpace;
        spaceLocations -= 1;
      }
      return res;
    }
  };

  Solution s;
  std::cout << s.justifyGroup({"string", "another", "strr"}, 30);
  return 0;
}