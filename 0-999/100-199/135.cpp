#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int candy(vector<int> ratings) {
      int n = ratings.size();
      int c = 1;
      int risingPeakIndex = 0;
      int risingPeakValue = 0;
      int currentCandyPerPerson = 1;
      bool upTrend = true;
      for (int i = 1; i < ratings.size();i++) {
        if (ratings[i] > ratings[i-1]) {
          currentCandyPerPerson++;
          c += currentCandyPerPerson;
          upTrend = true;
        } else if (ratings[i] < ratings[i-1]) {
          if (upTrend) {
            upTrend = false;
            risingPeakIndex = i - 1;
            risingPeakValue = currentCandyPerPerson;
            currentCandyPerPerson = 1;
          }
          int x = i - risingPeakIndex;
          if (x < risingPeakValue) {
            c += x;
          } else {
            c += x + 1;
          }
        } else if (ratings[i] == ratings[i-1]) {
          if (upTrend) {
            upTrend = false;
          }
          risingPeakIndex = i - 1;
          risingPeakValue = n + 1;
          currentCandyPerPerson = 1;
          c += currentCandyPerPerson;
        }
      }

      return c;
    }
  };

  Solution s;
  std::cout << s.candy({1, 0, 2});
  return 0;
}