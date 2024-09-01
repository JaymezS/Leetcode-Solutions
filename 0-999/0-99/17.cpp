#include <bits/stdc++.h>


using namespace std;


int main() {



class Solution {
public:
  vector<string> res;
  unordered_map<char, vector<string>> hash;

  vector<string> letterCombinations(string digits) {
    if (digits.length() == 0) {
      return {};
    }

    hash['2'] = {"a", "b", "c"};  
    hash['3'] = {"d", "e", "f"};   
    hash['4'] = {"g", "h", "i"};   
    hash['5'] = {"j", "k", "l"};   
    hash['6'] = {"m", "n", "o"};   
    hash['7'] = {"p", "q", "r", "s"};   
    hash['8'] = {"t", "u", "v"};   
    hash['9'] = {"w", "x", "y", "z"}; 

    rec(digits, "");
    return res;   
  }

  void rec(string arg, string word) { // second is the word, first is the remaining
    if (arg.length() == 0) {
      res.push_back(word);
      return;
    }

    for (auto& c: hash[arg[0]]) {
      rec(arg.substr(1, arg.size() - 1), word + c);
    }
  }
};





  return 0;
} 