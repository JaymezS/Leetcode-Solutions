#include <bits/stdc++.h>

using namespace std;

int main(){
  class KthLargest {
  public:
    int kl;
    vector<int> arr;

    KthLargest(int k, vector<int>& nums) {
      kl = k;
      sort(nums.begin(), nums.end(), greater<int>());
      arr = nums;
    }
    
    int add(int val) {
      int insertIndex = 0;

      int l = 0;
      int r = arr.size() - 1;
      int mid = 0;
      while (l <= r) {
        mid = (l + r) / 2;

        if (arr[mid] < val) {
          r = mid - 1;
          insertIndex = mid;
        } else if (arr[mid] > val) {
          l = mid + 1;
          insertIndex = l;
        } else {
          insertIndex = mid;
          break;
        }
      }



      arr.insert(arr.begin() + insertIndex, val);
      return arr[kl - 1];
    }
  };

  vector<int> v = {};
  KthLargest* k = new KthLargest(1, v);

  std::cout << k->add(-3);
  std::cout << k->add(-2);
  std::cout << k->add(-4);
  std::cout << k->add(0);
  std::cout << k->add(-4);

  return 0;
}