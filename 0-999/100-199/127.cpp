#include <bits/stdc++.h>

using namespace std;

int main(){






class SolutionBad {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int wordLength = beginWord.length();
    int arrSize = wordList.size();
    int target = -1;
    vector<vector<int>> next(arrSize, vector<int>(0));
    vector<bool> visited(arrSize, false);

    queue<pair<int, int>> q;

    for (int i = 0; i < arrSize; i++) {
      bool bgndifferent = false;

      for (int k = 0; k < wordLength; k++) {
        if (wordList[i][k] != beginWord[k]) {
          if (!bgndifferent) {
            bgndifferent = true;
          } else {
            bgndifferent = false;
            break;
          }
        }
      }
      if (bgndifferent) {
        q.push({i, 2});
      }

      if (wordList[i] == endWord) {
        target = i;
      }

      for (int j = i + 1; j < arrSize; j++) {
        bool different = false;
        for (int x = 0; x < wordLength; x++) {
          if (wordList[i][x] != wordList[j][x]) {
            if (!different) {
              different = true;
            } else {
              different = false;
              break;
            }
          }
        }
        if (different) {
          next[i].push_back(j);
          next[j].push_back(i);
        }
      }
    }


    while (q.size()) {
      int curr = q.front().first;

      int depth = q.front().second;
      q.pop();
      if (curr == target) {
        return depth;
      }

      if (!visited[curr]) {
        visited[curr] = true;
        for (auto& nextLocation: next[curr]) {
          q.push({nextLocation, depth+1});
        }
      }
    }
    return 0;
  }
};









  return 0;
}