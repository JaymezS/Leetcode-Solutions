#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<string> singleD = {
      "One",
      "Two", 
      "Three", 
      "Four", 
      "Five", 
      "Six", 
      "Seven", 
      "Eight", 
      "Nine", 
    };
    vector<string> tenMultiples = {
        "Ten",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety",
    };
    vector<string> tensD = {
      "Eleven",
      "Twelve",
      "Thirteen",
      "Fourteen",
      "Fifteen",
      "Sixteen",
      "Seventeen",
      "Eighteen",
      "Nineteen",
    };

    vector<string> sectors = {
      "",
      "Thousand",
      "Million",
      "Billion"
    };

    string numberToWords(int num) {
      if (num == 0) {
        return "Zero";
      }
      string res = "";

      int i = 0;
      while (num > 0) {
        int t = num % 1000;
        string r = convert(t);
        if (r.length()) {
          if (res.length()) {
            res = r + " " + sectors[i] +" "+ res;        
          } else {
            if (i == 0) {
              res = r;
            } else {
              res = r + " " + sectors[i];
            }
          }
        }
        num = floor(num / 1000);
        i++;
      }
      return res;
    }


    string convert(int num) {
      if (num == 0) {
        return "";
      }

      int h = floor(num / 100);
      int t = floor(num / 10) - h * 10;
      int s = num - h * 100 - t * 10;
      string res = "";
      if (h) {
        res += singleD[h - 1] + " Hundred";
      }
      if (t) {
        if (res.length()) {
          res += " ";
        } 
        if (t == 1) {
          if (s) {
            res += tensD[s - 1];
          } else {
            res += tenMultiples[0];
          }
        } else {
          res += tenMultiples[t - 1];
          if (s) {
            res += " " + singleD[s - 1];
          }
        }
      } else if (s) {
        if (res.length()) {
          res += " ";
        } 
        res += singleD[s - 1];
      }
      return res;
    }
  };

  Solution s;
  std::cout << s.numberToWords(1234567);

  return 0;
}