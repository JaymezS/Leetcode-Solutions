#include <bits/stdc++.h>

using namespace std;

int main(){
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> d;
    for (int i = 0; i < strs.size();i++) {
      string x = strs[i];
      sort(x.begin(), x.end());

      if (d.count(x)) {
        d[x].push_back(strs[i]);
      } else {
        d[x] = {strs[i]};
      }
    }

    vector<vector<string>> res;

    for (auto& item: d) {
      vector<string> y;
      for (int i = 0; i < item.second.size();i++) {
        y.push_back(item.second[i]);
      }
      res.push_back(y);
    }

    return res;
  }

};

Solution s;

vector<string> v = {"abc", "abc", "adc", "bca"};
s.groupAnagrams(v);
return 0;
}