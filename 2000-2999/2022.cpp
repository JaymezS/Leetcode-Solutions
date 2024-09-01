#include <bits/stdc++.h>


using namespace std;


int main() {



class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    int num = original.size();
    if (num != m * n) {
      return {};
    }

    vector<vector<int>> res(m, vector<int>(n, 0));
    int y = 0;
    int x = 0;
    for (int i = 0; i < num; i++) {
      res[y][x] = original[i];
      x++;
      if (x >= n) {
        y++;
        x = 0;
      }
    }

    return res;
  }
};





  return 0;
}