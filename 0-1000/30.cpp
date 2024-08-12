#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    vector<int> findSubstring(string s, vector<string> words) {
      vector<int> res;
      int wordCount = words.size();
      int wordLength = words[0].length();

      unordered_map<string, int> wordDict;
      for (int i = 0; i < wordCount; i++) {
        if (wordDict.count(words[i])) {
          wordDict[words[i]]++;
        } else {
          wordDict[words[i]] = 1;
        }
      }

      if (wordCount * wordLength > s.length()) {
        return {};
      }


      for (int startIndex = 0; startIndex < wordLength; startIndex++) {
        int unmatched = wordCount;

        unordered_map<string, int> tempDict;
        for (auto& it: wordDict) {
          tempDict[it.first] = it.second;
        }

        int p = startIndex;
        for (int i = 0; i < wordCount; i++) {
          p += wordLength;
          string substr = s.substr(p - wordLength, wordLength);
          if (tempDict.count(substr)) {
            tempDict[substr]--;
            if (tempDict[substr] >= 0) {
              unmatched--;
            } else {
              unmatched++;
            }
          } else {
            unmatched++;
          }
        }


        if (unmatched == 0) {
          res.push_back(startIndex);
        }
        p += wordLength;

        while (p <= s.length()) {
          string newSubstr = s.substr(p - wordLength, wordLength);
          string oldSubstr = s.substr(p - wordCount * wordLength - wordLength, wordLength);

          if (tempDict.count(newSubstr)) {
            tempDict[newSubstr]--;
            if (tempDict[newSubstr] >= 0) {
              unmatched--;
            } else {
              unmatched++;
            }
          } else {
            unmatched++;
          }

          if (tempDict.count(oldSubstr)) {
            tempDict[oldSubstr]++;
            if (tempDict[oldSubstr] <= 0) {
              unmatched--;
            } else {
              unmatched++;
            }
          } else {
            unmatched--;
          }


          if (unmatched == 0) {
            res.push_back(p - wordCount * wordLength);
          }

          p += wordLength;

        }
      }
      return res;
    }
  };

  Solution s;
  vector<int> sol = s.findSubstring("wordgoodgoodgoodbestword", {"word","good","best","good"});
  for (int i = 0; i < sol.size();i++) {
    std::cout << sol[i] << endl;
  }
  return 0;
}