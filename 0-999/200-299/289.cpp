#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:
    int X[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int Y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    void gameOfLife(vector<vector<int>>& board) {
      // 2 = dead -> alive
      // 3 = alive -> dead

      int height = board.size();
      int width = board[0].size();

      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          int ac = 0;
          for (int k = 0; k < 8; k++) {
            if (i + Y[k] >= 0 && i + Y[k] < height && j + X[k] >= 0 && j + X[k] < width) {
              if (board[i+Y[k]][j+X[k]] == 1 || board[i+Y[k]][j+X[k]] == 3) {
                ac++;
              }
            }
          }
          

          if (board[i][j] == 1) {
            if (ac < 2 || ac > 3) {
              board[i][j] = 3;
            }
          } else if (ac == 3) {
            board[i][j] = 2;
          }

        }
      }

      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          if (board[i][j] > 1) {
            board[i][j] = (board[i][j] - 1) % 2;
          }
        }
      }
    }
  };

  return 0;
}