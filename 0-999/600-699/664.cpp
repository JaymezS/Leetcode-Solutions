#include <bits/stdc++.h>

using namespace std;

int main(){




class Solution {
public:
  int strangePrinter(string s) {
    int length = s.length();

    if (length == 1) {
      return 1;
    }

    char prev = s[0];
    string ss = "";
    for (int i = 1; i < length; i++) {
      while (i < length) {
        if (s[i] == prev) {
          i++;
        } else {
          break;
        }
      }
      ss += prev;
      if (i < length) {
        prev = s[i];
      }
    }
    if (ss.back() != prev) {
      ss += prev;
    }

    s = ss;
    length = s.length();

    vector<vector<int>> movesNeeded(length, vector<int>(length + 1, 1));
    for (int i = length - 1; i >= 0; i--) {
      for (int k = 1; k < length + 1; k++) {
        int distance = min(length - i, k);
        if (s[i] == s[i + distance - 1]) {
          movesNeeded[i][distance] = movesNeeded[i][distance - 1];
        } else {
          movesNeeded[i][distance] = movesNeeded[i][distance - 1] + 1;
        }
        for (int j = 1; j < distance; j++) {
          movesNeeded[i][distance] = min(movesNeeded[i][distance], movesNeeded[i][j] + movesNeeded[i + j][distance - j]);
        }
      }
    }

    return movesNeeded[0][length];
  } 
};











  return 0;
}