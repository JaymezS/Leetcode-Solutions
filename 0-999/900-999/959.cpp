#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:

    int regionsBySlashes(vector<string> grid) {
      int width = grid[0].length();
      int height = grid.size();

      vector<vector<int>> parsedGraph(height * 3, vector<int>(width * 3, 0));


      for (int i = 0; i < height;i++) {
        for (int j = 0; j < width; j++) {
          char c = grid[i][j];
          if (c == '/') {
            parsedGraph[i * 3][j * 3 + 2] = 1;
            parsedGraph[i * 3 + 1][j * 3 + 1] = 1;
            parsedGraph[i * 3 + 2][j * 3] = 1;
          } else if (c == '\\') {
            parsedGraph[i * 3][j * 3] = 1;
            parsedGraph[i * 3 + 1][j * 3 + 1] = 1;
            parsedGraph[i * 3 + 2][j * 3 + 2] = 1;  
          }
        }
      }

      vector<vector<bool>> visited(height * 3, vector<bool>(width * 3, false));

      int total = 0;

      for (int y = 0; y < height * 3; y++) {
        for (int x = 0; x < width * 3; x++) {
          if (!visited[y][x] && parsedGraph[y][x] == 0) {
            // bfs here
            queue<pair<int, int>> q;
            q.push({x, y});
            while (q.size()) {
              pair<int, int> coord = q.front();
              int cx = coord.first;
              int cy = coord.second;
              visited[cy][cx] = true;
              q.pop();

              if (cy + 1 < height * 3) {
                if (!visited[cy + 1][cx] && parsedGraph[cy + 1][cx] == 0) {
                  q.push({cx, cy + 1});
                } 
              }
              if (cy - 1 >= 0) {
                if (!visited[cy - 1][cx] && parsedGraph[cy - 1][cx] == 0) {
                  q.push({cx, cy - 1});
                } 
              }              
              if (cx + 1 < width * 3) {
                if (!visited[cy][cx+1] && parsedGraph[cy][cx+1] == 0) {
                  q.push({cx+1, cy});
                } 
              }              
              if (cx - 1 >= 0) {
                if (!visited[cy][cx - 1] && parsedGraph[cy][cx - 1] == 0) {
                  q.push({cx - 1, cy});
                } 
              }
            }

            total++;
          }
        }
      }

      return total;
    }
  };

  Solution s;
  std::cout << s.regionsBySlashes({"\\/ /\\\\ / ","\\/\\ \\ \\\\/","//\\ \\/\\\\\\","\\ //\\/\\\\\\","/ \\\\/ \\ /","\\\\/\\ /  \\"," \\/ /   \\","\\\\\\/  \\\\ ","\\\\\\ \\//  "});
  return 0;
}