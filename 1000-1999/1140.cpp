#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  int stoneGameII(vector<int>& piles) {
    int length = piles.size();

    vector<int> sums(length, 0);
    sums[length - 1] = piles.back();
    for (int i = length - 2; i >= 0 ; i--) {
      sums[i] = (piles[i] + sums[i + 1]);
    }

    vector<vector<int>> maxFrom(length, vector<int>(length + 1, 0));
    for (int i = length - 1; i >= 0; i--) {
      for (int m = 1; m <= length; m++) {
        if (i + 2 * m >= length) {
          maxFrom[i][m] = sums[i];
        } else {
          for (int x = 1; x <= m * 2; x++) {
            maxFrom[i][m] = max(maxFrom[i][m], sums[i] - maxFrom[i + x][max(x, m)]);
          }
        }
      }
    }

    return maxFrom[0][1];
  }
};










  return 0;
}