#include <bits/stdc++.h>

using namespace std;

int main(){






class Solution {
public:
  int minSteps(int n) {
    if (n == 1) {
      return 0;
    }
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < n + 1; i++) {
      bool isPrime = true;
      for (int j = 0; j < primes.size(); j++) {
        if (i % primes[j] == 0) {
          isPrime = false;
          break;
        }
      }
      if (isPrime) {
        primes.push_back(i);
      }
    }

    int c = 0;
    int currDivisor = 0;
    while (n > 1) {
      if (n % primes[currDivisor] == 0) {
        c += primes[currDivisor];
        n /= primes[currDivisor];
      } else {
        currDivisor++;
      }
    }
    return c;
  }
};









  return 0;
}
