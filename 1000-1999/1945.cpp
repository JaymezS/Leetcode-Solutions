#include <bits/stdc++.h>


using namespace std;


int main() {



class Solution {
public:
  int getLucky(string s, int k) {
    string a = "";
    for (int i = 0;  i < s.size(); i++) {
      a  = a + to_string(s[i] - 'a' + 1);
    }

    for (int j = 0; j < k; j++) {
      a = trans(a);
    }
    return stoi(a);
  }


  string trans(string arg) {
    int c = 0;
    for (int i = 0; i < arg.size(); i++) {
      c += arg[i] - '0';
    }

    return to_string(c);
  }
};





  return 0;
}