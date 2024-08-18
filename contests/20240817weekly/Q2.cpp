#include <bits/stdc++.h>

using namespace std;

int main(){






class Solution {
public:
  long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
    int length = energyDrinkA.size();

    vector<long long> maxA;
    vector<long long> maxB;
    maxA.push_back(energyDrinkA[0]);
    maxB.push_back(energyDrinkB[0]);
    maxA.push_back(energyDrinkA[1] + maxA[0]);
    maxB.push_back(energyDrinkB[1] + maxB[0]);


    for (int i = 2; i < length; i++) {
      maxA.push_back(max(maxB[i - 2], maxA[i - 1]) + energyDrinkA[i]);
      maxB.push_back(max(maxA[i - 2], maxB[i - 1]) + energyDrinkB[i]);
    }

    return max(maxA.back(), maxB.back());
  }
};







  return 0;
}