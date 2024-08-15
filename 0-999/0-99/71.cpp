#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    string simplifyPath(string path) {
      vector<string> s;
      int n = path.length();
      if (n == 1) {
        return "/";
      }
      int p1 = 0;
      int p2 = 0;

      while (p2 < n) {
        if (path[p2] == '/') {
          if (p2 - p1 > 1) {
            string x = path.substr(p1 + 1, p2 - p1 - 1);
            if (x == "..") {
              if (s.size()) {
                s.pop_back();
              }
            } else if (x != ".") {
              s.push_back(x);
            }
          }
          p1 = p2;
        }
        p2++;
      }

      if (p2-1 != p1) {
        if (p2 - p1 > 1) {
          string x = path.substr(p1 + 1, p2 - p1 - 1);
          if (x == "..") {
            if (s.size()) {
              s.pop_back();
            }
          } else if (x != ".") {
            s.push_back(x);
          }
        }
        p1 = p2;
      }

      string res = "";
      for (auto& i: s) {
        res += "/" + i;
      }
      if (res == "") {
        return "/";
      }
      return res;
    }
  };
  return 0;
}