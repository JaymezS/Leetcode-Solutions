#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  int maxDistance(vector<vector<int>>& arrays) {
    int absMax = INT_MIN;
    int absMin = INT_MAX;
    int secMax = INT_MIN;
    int secMin = INT_MAX;
    bool same = false;

    for (auto& v: arrays) {
      int cmin = v.front();
      int cmax = v.back();

      if (cmax > absMax && cmin < absMin) {
        same = true;
        secMax = absMax;
        secMin = absMin;
        absMax = cmax;
        absMin = cmin;
      } else if (cmax < absMax && cmin > absMin) {
        if (cmax > secMax) {
          secMax = cmax;
        }
        if (cmin < secMin) {
          secMin = cmin;
        }
      } else {
        same = false;

        if (cmax > absMax) {
          secMax = absMax;
          absMax = cmax;
        } else if (cmin < absMin) {
          secMin = absMin;
          absMin = cmin;
        }
      }
    }

    if (same) {
      return max(absMax - secMin, secMax - absMin);
    } else {
      return absMax - absMin;
    }
  }
};










  return 0;
}