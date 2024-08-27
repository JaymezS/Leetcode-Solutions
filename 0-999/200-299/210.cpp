#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> requiredBy(numCourses, vector<int>(0));
    vector<int> dependents(numCourses, 0);
    vector<int> res = {};

    for (auto& pair: prerequisites) {
      requiredBy[pair[1]].push_back(pair[0]);
      dependents[pair[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (dependents[i] == 0) {
        q.push(i);
      }
    }


    while (q.size()) {
      int courseAvailable = q.front();
      q.pop();

      res.push_back(courseAvailable);

      for (auto& nextCourseToTake: requiredBy[courseAvailable]) {
        dependents[nextCourseToTake]--;
        if (dependents[nextCourseToTake] == 0) {
          q.push(nextCourseToTake);
        }
      }
    }


    for (auto& x: dependents) {
      if (x != 0) {
        return {};
      }
    }
    return res;
  }
};










  return 0;
}