#include <bits/stdc++.h>


using namespace std;


int main() {




class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {\
    vector<vector<int>> next(numCourses, vector<int>(0, 0)); // course i require n[i];

    for (auto& pair: prerequisites) {
      next[pair[0]].push_back(pair[1]);
    }

    for (auto& pair: prerequisites) {

    }
    return true;
  }
};




  return 0;
}