#include <bits/stdc++.h>

using namespace std;

int main(){




class Solution {
public:
  long long maximumValueSum(vector<vector<int>>& board) {
    int height = board.size();
    int width = board[0].size();
    pair<int, int> biggestValRook(-1, INT_MIN); // first = xlocation, second = value
    pair<int, int> secondValRook(-1, INT_MIN);
    pair<int, int> smallestValRook(-1, INT_MIN);


    for (auto& row: board) {
      vector<int> maxes;
      maxes.push_back(0);
      for (int i = 1; i < width; i++) {
        if (row[i] > row[maxes[0]]) {
          maxes.clear();
          maxes.push_back(i);
        } else if (row[i] == row[maxes[0]]) {
          maxes.push_back(i);
        }
      }


      int val = row[maxes[0]];
      if (val > biggestValRook.second) {
        if (biggestValRook.first == maxes[0]) {
          biggestValRook.second = val;

        } else if (secondValRook.first == maxes[0]) {
          secondValRook.first = biggestValRook.first;
          secondValRook.second = biggestValRook.second;
          biggestValRook.first = maxes[0];
          biggestValRook.second = val;

        } else {
          smallestValRook.first = secondValRook.first;
          smallestValRook.second = secondValRook.second;
          secondValRook.first = biggestValRook.first;
          secondValRook.second = biggestValRook.second;
          biggestValRook.first = maxes[0];
          biggestValRook.second = val;

        } 
      } else if (val > secondValRook.second) {
        int x = 0;
        while (x < maxes.size()) {
          if (maxes[x] != biggestValRook.first) {
            break;
          }
          x++;
        }
        if (x == maxes.size()) {
          std::cout << "contd";
          continue;
        }

        if (secondValRook.first == maxes[x]) {
          secondValRook.second = val;
        } else {
          smallestValRook.first = secondValRook.first;
          smallestValRook.second = secondValRook.second;
          secondValRook.first = maxes[x];
          secondValRook.second = val;
        }
      } else if (val > smallestValRook.second) {
        int x = 0;
        while (x < maxes.size()) {
          if (maxes[x] != biggestValRook.first && maxes[x] != secondValRook.first) {
            break;
          }
          x++;
        }
        if (x == maxes.size()) {
          std::cout << "contd";
          continue;
        }
        smallestValRook.first = maxes[x];
        smallestValRook.second = val;
      }
    }
    std::cout << smallestValRook.second <<  ", " << secondValRook.second<< ", "<< biggestValRook.second;
    return smallestValRook.second + secondValRook.second + biggestValRook.second;
  }
};











  return 0;
}