#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int trap(vector<int> height) {
      int n = int(height.size());
      int total = 0;
      int* lmax = new int[n]{0};
      int* rmax = new int[n]{0};
      int m = 0;
      for (int i = 1; i < n;i++) {
        if (height[i-1] > m) {
          m = height[i - 1];
        }
        lmax[i] = m;
      }
      m = 0;
      for (int i = n - 2; i >= 0; i--) {
        if (height[i+1] > m) {
          m = height[i + 1];
        }
        rmax[i] = m;
      }

      for (int i = 0; i < n;i++) {
        int cont = min(lmax[i], rmax[i]) - height[i];
        if (cont > 0) {
          total += cont;
        }
      }
      delete[] rmax, lmax;
      return total;
    }
  };
  Solution s;
  std::cout << s.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
}