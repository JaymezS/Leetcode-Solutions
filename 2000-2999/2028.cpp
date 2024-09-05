#include <bits/stdc++.h>


using namespace std;


int main() {




class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int total = 0;
    int totalNum = rolls.size() + n;
    for (auto& c: rolls) {
      total += c;
    }   
    
    int dTotal = mean * totalNum;
    int sumNeeded = dTotal - total;

    if (sumNeeded < n || sumNeeded > 6 * n) {
      return {};
    }

    int baseVal = sumNeeded / n;
    vector<int> res(n, baseVal);

    int rem = sumNeeded - (baseVal * n);
    for (int i = 0; i < rem; i++) {
      res[i]++;
    }

    return res;
  }
};




  return 0;
}