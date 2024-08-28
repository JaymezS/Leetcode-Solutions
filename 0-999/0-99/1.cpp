#include <bits/stdc++.h>

using namespace std;

int main(){







class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> d;
        for (int i = 0; i < nums.size(); i++) {
            if (d.count(target - nums[i])) {
                return {d[target - nums[i]], i};
            }
            d[nums[i]] = i;
        }
        return {};
    }
};






  return 0;
}