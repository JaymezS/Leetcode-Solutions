#include <bits/stdc++.h>


using namespace std;


int main() {




class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> d(101, 0);
        int c = 0;
        for (int& x: nums) {
            c += d[x];
            d[x]++;
        }
        return c;
    }
};




  return 0;
}