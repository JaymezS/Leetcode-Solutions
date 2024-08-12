#include <bits/stdc++.h> 

int main() {
  class Solution {
    public:
      int minimumPushes(std::string word) {


        const int length = word.length();
        char* ca = new char[length + 1];
        std::strcpy(ca, word.c_str());
        int counter[26] = {0};
        for (int i = 0; i < length; i++) {
          counter[int(ca[i])-97]++;
        }

        int c = 0;
        int cost = 1;
        int used = 0;

        std::sort(counter, counter + 26, std::greater<int>());
        for (int i = 0; i < 26;i++) {
          c += cost * counter[i];
          used++;
          if (used >= 8) {
            used = 0;
            cost++;
          }
          if (counter[i] == 0) {
            return c;
          }
        }

        delete[] ca;
        return c;
      }
  };

  Solution s;
  std::cout << s.minimumPushes("aabbccddeeffgghhiiiiii");
}

