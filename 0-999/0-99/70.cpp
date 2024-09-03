#include <bits/stdc++.h>


using namespace std;


int main() {



class Solution {
public:
  int climbStairs(int n) {
    vector<int> ways(n + 1, 1);
    for (int i = 2; i < n + 1; i++) {
      ways[i] = ways[i - 1] + ways[i - 2];
    }
    return ways[n];
  } 
};





  return 0;
}