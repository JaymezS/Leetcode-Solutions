#include <bits/stdc++.h>

using namespace std;


int main() {

  class Solution {
  public:
    string kthDistinct(vector<string>& arr, int k) {
      unordered_set<string> u;
      unordered_set<string> d;

      // unordered sets made it 7x faster than regular sets idfk why

      for (int i = 0; i < arr.size();i++) {
        if (!d.count(arr[i])) {
          if (!u.count(arr[i])) {
            u.insert(arr[i]);
          } else {
            d.insert(arr[i]);
            u.erase(arr[i]);
          }
        }
      }

      int unique = 0;

      for (int i = 0; i < arr.size();i++) {
        if (u.count(arr[i])) {
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
