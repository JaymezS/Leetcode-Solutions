#include <bits/stdc++.h>

using namespace std;

int main(){
class Solution {
public:
  int calculate(string s) {
    vector<char> op;
    vector<int> nums;


    op.push_back('(');
    s += ")";

    int n = -1;
    bool addNumberAfterBracket = false;
    for (int j = 0; j < s.length(); j++) {
      char i = s[j];
      if (i != ' ') {
        int x = i - '0';
        if (0 <= x && x <= 9) {
          if (n == -1) {
            n = x;
          } else {
            n *= 10;
            n += x;
          }
        } else {
          // is operator

          if (n != -1)
          {
            addNumberAfterBracket = true;
            nums.push_back(n);
            n = -1;
          }


          if (i == '+' || i == '-') {
            if (i == '-' && !addNumberAfterBracket && op.back() == '(') {
              nums.push_back(0);
            }
            while (!op.empty()) {
              if (op.back() == '(') {
                break;
              } else {
                char k = op.back();
                op.pop_back();
                int sec = nums.back();
                if (k == '+') {
                  nums[nums.size() - 2] += sec;
                } else {
                  nums[nums.size() - 2] -= sec;
                }
                nums.pop_back();
              }
            }
            op.push_back(i);
          }
          if (i == '(') {
            op.push_back(i);
            addNumberAfterBracket = false;
          } else if (i == ')') {
              
            while (op.back() != '(') {
              char k = op.back();
              op.pop_back();
              int sec = nums.back();
              if (k == '+') {
                nums[nums.size() - 2] += sec;
              } else {
                nums[nums.size() - 2] -= sec;
              }
              nums.pop_back();
            }

            op.pop_back();
          }
        } 
      }
    }
    if (n != -1) {
      nums.push_back(n);
    }

    return nums[0];
  }
};

Solution s;
std::cout << s.calculate("(-1) - (2) - (3)");
return 0;
}