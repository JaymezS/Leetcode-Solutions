#include <bits/stdc++.h>


using namespace std;


int main() {



class SolutionBad {
public:
  vector<vector<int>> res;
  vector<int> nums;
  int s;
  vector<vector<int>> combine(int n, int k) {
    for (int i = 1; i < n + 1; i++) {
      nums.push_back(i);
    }
    s = k;

    for (int i = 0; i < nums.size(); i++) {
      recurse({}, i);
    }
    return res;
  }

  void recurse(vector<int> curr, int index) {
    curr.push_back(nums[index]);

    if (curr.size() == s) {
      res.push_back(curr);
      return;
    }

    for (int i = index + 1; i < nums.size(); i++) {
      recurse(curr, i);
    }
  }
};



class Solution {
public:
  vector<vector<int>> res;
  vector<int> nums, paths;
  int s;
  vector<vector<int>> combine(int n, int k) {
    for (int i = 1; i < n + 1; i++) {
      nums.push_back(i);
    }
    s = k;

    recurse(0);
    return res;
  }

  void recurse(int index) {

    if (paths.size() == s) {
      res.push_back(paths);
      return;
    }

    for (int i = index; i < nums.size(); i++) {
      paths.push_back(nums[i]);
      recurse(i + 1);
      paths.pop_back();
    }
  }
};




  return 0;
}