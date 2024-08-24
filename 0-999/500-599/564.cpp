#include <bits/stdc++.h>

using namespace std;

int main(){


// WIP NOT FINISHED

class Solution {
public:
  string nearestPalindromic(string n) {
    int length = n.length();

    if (length == 1) {
      return to_string(stoi(n) - 1);
    }
    long num = stol(n);

    if (num % 10 == 0) {
      return to_string(stol(n) - 1);      
    }
    if ((num - 1) % 10 == 0) {
      return to_string(stol(n) - 2);      
    }
    if (num + 1 % 10 == 0) {
      return to_string(stol(n) + 2);      
    }

    long root1;
    long root2;
    
    if (length % 2 == 0) {
      root1 = stol(n.substr(0, length / 2));
      root2 = stol(n.substr(length / 2, length / 2));
    } else {
      root1 = stol(n.substr(0, length / 2 + 1));
      root2 = stol(n.substr(length / 2, length / 2 + 1)); 
    }

    
  }
};











  return 0;
}