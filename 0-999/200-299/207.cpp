#include <bits/stdc++.h>


using namespace std;


int main() {




class SolutionBad {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {\
    vector<vector<int>> next(numCourses, vector<int>(0, 0)); // course i require n[i];
    vector<bool> visited(numCourses, false);



    for (auto& pair: prerequisites) {
      next[pair[1]].push_back(pair[0]);
    }

    for (int i = 0; i < prerequisites.size(); i++) {
      if (!visited[prerequisites[i][0]]) {
        stack<pair<int, set<int>>> s;
        s.push({prerequisites[i][0], {}});

        while (s.size()) {
          int prereq = s.top().first;
          set<int> cycled = s.top().second;
          s.pop();

          if (cycled.count(prereq)) {
            return false;
          }

          cycled.insert(prereq);
          
          if (visited[prereq]) {
            continue;
          }
          visited[prereq] = true;

          for (int n: next[prereq]) {
            s.push({n, cycled});
          }
        }
      }
    }
      return true;
  }
};

// every course has n requirements, if n == 0, course is good, all the courses that requires it have their n reduced by 1

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> next(numCourses, vector<int>(0)); // course i is needed for n[i];
    vector<int> dependencies(numCourses, 0);
    int s;
    for (auto& pair: prerequisites) {
      next[pair[1]].push_back(pair[0]);
      dependencies[pair[0]]++;
      s++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (dependencies[i] == 0) {
        q.push(i);
      }
    }

    while (q.size()) {
      int availableCourse = q.front();
      q.pop();
      for (int x: next[availableCourse]) {
        dependencies[x]--;
        s--;
        if (dependencies[x] == 0) {
          q.push(x);
        }
      }
    }

    return s == 0;
  }
};


  return 0;
}