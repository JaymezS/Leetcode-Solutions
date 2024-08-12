#include <bits/stdc++.h>

using namespace std;

typedef map<string, int> counter;

int main() {

  class Solution {
  public:
    string kthDistinct(vector<string>& arr, int k) {
      counter c;

      for (int i = 0; i < arr.size();i++) {
        if (c[arr[i]]) {
          c[arr[i]]++;
        } else {
          c[arr[i]] = 1;
        }
      }

      int unique = 0;

      for (int i = 0; i < arr.size();i++) {
        if (c[arr[i]] == 1) {
          unique++;
          if (unique == k) {
            return arr[i];
          }
        }
      }
      return "";
    }
  };

  Solution s;
  vector<string> t = {"afd,", "byty,", "c", "b"};
  std::cout << s.kthDistinct(t, 2);
  return 0;
}
