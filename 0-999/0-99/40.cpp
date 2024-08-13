#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<vector<int>> results = {};

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end(), less<int>());

      recursiveSum(0, target, candidates, {});

      return results;
    }


    void recursiveSum(int index, int target, vector<int>& remaining, vector<int> path) {
      for (int i = index; i < remaining.size(); i++) {
        
        if (i > 0) {
          if (remaining[i] == remaining[i-1] && i != index) {
            continue;
          }
        }



        if (remaining[i] > target) {
          return;
        }
        if (remaining[i] == target) {
          path.push_back(remaining[i]);
          results.push_back(path);
          return;
        }
        vector<int> y = path;

        y.push_back(remaining[i]);
        recursiveSum(i + 1, target - remaining[i], remaining, y);
      }
    }


  };

  Solution s;
  vector<int> v = {10,1,2,7,6,1,5};
  vector<vector<int>> x = s.combinationSum2(v, 8);
  
  for (auto& path: x) {
    for (auto& val: path) {
      std::cout << val << ", ";
    }
    std::cout << endl;
  }
  return 0;
}