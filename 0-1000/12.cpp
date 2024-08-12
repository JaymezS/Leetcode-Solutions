#include <bits/stdc++.h>

using namespace std;

typedef map<int, string> dict;

int main(){

  class Solution {
  public:
    string intToRoman(int num) {
      vector<pair<int, string>> combinations = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
      string s = "";
      int cur = 0;
      while (num > 0) {
        if (num >= combinations[cur].first){
          s += combinations[cur].second;
          num -= combinations[cur].first;
        } else {
          cur++;
        }
      }
      return s;
    }
  };
  return 0;
}