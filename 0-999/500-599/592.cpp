#include <bits/stdc++.h>

using namespace std;

int main(){






class Solution {
public:
  string fractionAddition(string expression) {
    int length = expression.size();
    if (expression[0] == '-') {
      expression = "0/1" + expression;
      length = expression.size();
    }

    int firstNum = 0;
    int secNum = 0;
    int currNum = 0;
    bool isAddition = true;

    int numerator = 0;
    int denominator = 1;
    for (int i = 0; i < length; i++) {
      if (expression[i] == '+' || expression[i] == '-') {
        secNum = currNum;
        currNum = 0;

        if (isAddition) {
          numerator = numerator * secNum + firstNum * denominator;
        } else {
          numerator = numerator * secNum - firstNum * denominator;
        }
        denominator *= secNum;
        if (expression[i] == '+') {
          isAddition = true;
        } else {
          isAddition = false;
        }
      } else if (expression[i] == '/') {
        firstNum = currNum;
        currNum = 0;
      } else {
        currNum *= 10;
        currNum += expression[i] - '0';
      }
    }

    secNum = currNum;
    if (isAddition) {
      numerator = numerator * secNum + firstNum * denominator;
    } else {
      numerator = numerator * secNum - firstNum * denominator;
    }
    denominator *= secNum;
    int divisor = 2;
    while (divisor <= min(denominator, abs(numerator))) {
      while (denominator % divisor == 0 && numerator % divisor == 0) {
        denominator /= divisor;
        numerator /= divisor;
      }
      divisor++;
    }

    if (numerator == 0) {
      return "0/1";
    }
    return to_string(numerator) + "/" + to_string(denominator);
  }
};










  return 0;
}