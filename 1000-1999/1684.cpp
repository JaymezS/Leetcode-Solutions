#include <bits/stdc++.h>


using namespace std;


int main() {




class Solution {
public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    bool table[26] = {false};
    for (char& c: allowed) {
      table[c - 'a'] = true;
    }

    int c = 0;
    for (string& s: words) {
      bool can = true;
      for (int i = 0; i < s.length(); i++) {
        if (!table[s[i] - 'a']) {
          can = false;
          break;
        }
      }

      if (can) {
        c++;
      }
    }

    return c;
  }
};




  return 0;
}