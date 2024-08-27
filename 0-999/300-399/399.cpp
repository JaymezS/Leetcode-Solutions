#include <bits/stdc++.h>

using namespace std;

int main(){



class Solution {
public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> d;
    for (int i = 0; i < equations.size(); i++) {
      d[equations[i][0]].push_back({equations[i][1], values[i]});
      d[equations[i][1]].push_back({equations[i][0], double(1)/values[i]});
    }

    vector<double> res;
    for (auto& p: queries) {
      string s =  p[0];
      string e = p[1];

      queue<pair<string, double>> q;
      set<string> visited;
      q.push({s, double(1)});
      bool found = false;
      while (q.size() && !found) {
        string curr = q.front().first;
        double val = q.front().second;
        q.pop();

        if (d.count(curr) && !visited.count(curr)) {
          visited.insert(curr);
          for (auto& newPair: d[curr]) {
            if (newPair.first == e) {
              res.push_back(val * newPair.second);
              found = true;
              break;
            } else {
              q.push({newPair.first, val * newPair.second});
            }
          }
        }
      }

      if (!found) {
        res.push_back(double(-1));
      }
    }
    return res;
  }
};












  return 0;
}