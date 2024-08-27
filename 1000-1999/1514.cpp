#include <bits/stdc++.h>

using namespace std;

int main(){





class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<vector<pair<int, double>>> m(n, vector<pair<int, double>>(0));
    for (int i = 0; i < edges.size(); i++) {
      m[edges[i][0]].push_back({edges[i][1], succProb[i]});
      m[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    vector<double> maxDist(n, double(0));
    maxDist[start_node] = double(1);
    queue<int> q;
    q.push(start_node);


    while (q.size()) {
      int node = q.front();
      q.pop();

      for (auto& next: m[node]) {
        if (maxDist[next.first] < maxDist[node] * next.second) {
          maxDist[next.first] = maxDist[node] * next.second;
          q.push(next.first);
        }
      }
    }

    return maxDist[end_node];
  }
};










  return 0;
}