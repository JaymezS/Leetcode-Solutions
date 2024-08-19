#include <bits/stdc++.h>

using namespace std;

int main(){



class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> u;
    u.push_back(1);
    int c[3] = {0, 0, 0};
    for (int i = 1; i < n; i++) {
      u.push_back(min(u[c[0]] * 2, min(u[c[1]] * 3, u[c[2]] * 5)));
      if (u.back() == u[c[0]] * 2) {
        c[0]++;
      }
      if (u.back() == u[c[1]] * 3) {
        c[1]++;
      }
      if (u.back() == u[c[2]] * 5) {
        c[2]++;
      }
    }

    return u.back();
  }
};












  return 0;
}