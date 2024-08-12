#include <bits/stdc++.h>

using namespace std;

int main(){
  class Solution {
  public:

    int regionsBySlashes(vector<string> grid) {
      int width = grid[0].length();
      int height = grid.size();

      vector<vector<int>> visited(height, vector<int>(width, 0));
      // 0 is not visited, 1 is top/left, 4 is bottom-right, 3 is top/right, 2 is bottom/left, 5 is all
      // states: top = 0, bot = 1 , left = 2, right = 3
      int total = 0;
      for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
          if (visited[y][x] == 0 || visited[y][x] == 4 || visited[y][x] == 2) {
            // bfs here
            queue<pair<pair<int, int>, int>> q;
            q.push({{x, y}, 0});
            while (q.size()) {

              // get info
              pair<int, int> coord = q.front().first;
              int cx = coord.first;
              int cy = coord.second;
              int d = q.front().second;
              q.pop();
              char ca = grid[cy][cx];


              if (visited[cy][cx] == 5) {
                continue;
              }


              bool goLeft = false;
              bool goRight = false;
              bool goTop = false;
              bool goBot = false;

              // decide how to modify the "visited" branch
              if (ca == '/') {
                if (d == 0 || d == 2) {
                  if (visited[cy][cx] != 4 && visited[cy][cx] != 0) {
                    continue;
                  }
                  visited[cy][cx] += 1;
                  if (cx - 1 >= 0) {
                    goLeft = true;
                  }
                  if (cy - 1 >= 0) {
                    goTop = true;
                  }
                } else {
                  if (visited[cy][cx] != 1 && visited[cy][cx] != 0) {
                    continue;
                  }
                  visited[cy][cx] += 4;

                  if (cx + 1 < width) {
                    goRight = true;
                  }
                  if (cy + 1 < height) {
                    goBot = true;
                  }
                }
              } else if (ca == '\\') {
                if (d == 0 || d == 3) {
                  if (visited[cy][cx] != 2 && visited[cy][cx] != 0) {
                    continue;
                  }
                  visited[cy][cx] += 3;

                  if (cx + 1 < width) {
                    goRight = true;
                  } 
                  if (cy - 1 >= 0) {
                    goTop = true;
                  }
                } else {
                  if (visited[cy][cx] != 3 && visited[cy][cx] != 0) {
                    continue;
                  }
                  visited[cy][cx] += 2;

                  if (cx - 1 >= 0) {
                    goLeft = true;
                  }
                  if (cy + 1 < height) {
                    goBot = true;
                  }
                }
              } else {
                visited[cy][cx] = 5;
                if (cx + 1 < width) {
                  goRight = true;
                } 
                if (cy - 1 >= 0) {
                  goTop = true;
                }
                if (cx - 1 >= 0) {
                  goLeft = true;
                }
                if (cy + 1 < height) {
                  goBot = true;
                }
              }

              if (goLeft) {
                if (visited[cy][cx - 1] < 5) {
                  char c = grid[cy][cx - 1];
                  if (!
                    ((c == '/' && visited[cy][cx - 1] == 4) ||
                    (c == '\\' && visited[cy][cx - 1] == 3))
                  ) {
                    q.push({{cx - 1, cy}, 3});
                  }
                }
              }
              if (goRight) {
                if (visited[cy][cx + 1] < 5) {
                  char c = grid[cy][cx + 1];
                  if (
                    !((c == '/' && visited[cy][cx + 1] == 1) ||
                    (c == '\\' && visited[cy][cx + 1] == 2))
                  ) {
                    q.push({{cx + 1, cy}, 2});
                  }
                }
              }
              if (goTop) {
                if (visited[cy-1][cx] < 5) {
                  char c = grid[cy-1][cx];
                  if (
                    !((c == '/' && visited[cy-1][cx] == 4) ||
                    (c == '\\' && visited[cy-1][cx] == 2))
                  ) {
                    q.push({{cx, cy - 1}, 1});
                  }
                }
              }
              if (goBot) {
                if (visited[cy+1][cx] < 5) {
                  char c = grid[cy+1][cx];
                  if (
                    !((c == '/' && visited[cy+1][cx] == 1) ||
                    (c == '\\' && visited[cy+1][cx] == 3))
                  ) {
                    q.push({{cx, cy + 1}, 0});
                  }
                }
              }

            }

            total++;
          }
        }
      }



        // check last row

      int y = height - 1;
      for (int x = 0; x < width; x++) {
        if (visited[y][x] == 0 || visited[y][x] == 1 || visited[y][x] == 3) {
          // bfs here
          queue<pair<pair<int, int>, int>> q;
          q.push({{x, y}, 1});
          while (q.size()) {

            // get info
            pair<int, int> coord = q.front().first;
            int cx = coord.first;
            int cy = coord.second;
            int d = q.front().second;
            q.pop();
            char ca = grid[cy][cx];


            if (visited[cy][cx] == 5) {
              continue;
            }


            bool goLeft = false;
            bool goRight = false;
            bool goTop = false;
            bool goBot = false;

            // decide how to modify the "visited" branch
            if (ca == '/') {
              if (d == 0 || d == 2) {
                if (visited[cy][cx] != 4 && visited[cy][cx] != 0) {
                  continue;
                }
                visited[cy][cx] += 1;
                if (cx - 1 >= 0) {
                  goLeft = true;
                }
                if (cy - 1 >= 0) {
                  goTop = true;
                }
              } else {
                if (visited[cy][cx] != 1 && visited[cy][cx] != 0) {
                  continue;
                }
                visited[cy][cx] += 4;

                if (cx + 1 < width) {
                  goRight = true;
                }
                if (cy + 1 < height) {
                  goBot = true;
                }
              }
            } else if (ca == '\\') {
              if (d == 0 || d == 3) {
                if (visited[cy][cx] != 2 && visited[cy][cx] != 0) {
                  continue;
                }
                visited[cy][cx] += 3;

                if (cx + 1 < width) {
                  goRight = true;
                } 
                if (cy - 1 >= 0) {
                  goTop = true;
                }
              } else {
                if (visited[cy][cx] != 3 && visited[cy][cx] != 0) {
                  continue;
                }
                visited[cy][cx] += 2;

                if (cx - 1 >= 0) {
                  goLeft = true;
                }
                if (cy + 1 < height) {
                  goBot = true;
                }
              }
            } else {
              visited[cy][cx] = 5;
              if (cx + 1 < width) {
                goRight = true;
              } 
              if (cy - 1 >= 0) {
                goTop = true;
              }
              if (cx - 1 >= 0) {
                goLeft = true;
              }
              if (cy + 1 < height) {
                goBot = true;
              }
            }

            if (goLeft) {
              if (visited[cy][cx - 1] < 5) {
                char c = grid[cy][cx - 1];
                if (!
                  ((c == '/' && visited[cy][cx - 1] == 4) ||
                  (c == '\\' && visited[cy][cx - 1] == 3))
                ) {
                  q.push({{cx - 1, cy}, 3});
                }
              }
            }
            if (goRight) {
              if (visited[cy][cx + 1] < 5) {
                char c = grid[cy][cx + 1];
                if (
                  !((c == '/' && visited[cy][cx + 1] == 1) ||
                  (c == '\\' && visited[cy][cx + 1] == 2))
                ) {
                  q.push({{cx + 1, cy}, 2});
                }
              }
            }
            if (goTop) {
              if (visited[cy-1][cx] < 5) {
                char c = grid[cy-1][cx];
                if (
                  !((c == '/' && visited[cy-1][cx] == 4) ||
                  (c == '\\' && visited[cy-1][cx] == 2))
                ) {
                  q.push({{cx, cy - 1}, 1});
                }
              }
            }
            if (goBot) {
              if (visited[cy+1][cx] < 5) {
                char c = grid[cy+1][cx];
                if (
                  !((c == '/' && visited[cy+1][cx] == 1) ||
                  (c == '\\' && visited[cy+1][cx] == 3))
                ) {
                  q.push({{cx, cy + 1}, 0});
                }
              }
            }

          }

          total++;
        }
      }
      return total;
    }
  };

  Solution s;
  std::cout << s.regionsBySlashes(
    {
"\\/ /\\\\ / ","\\/\\ \\ \\\\/","//\\ \\/\\\\\\","\\ //\\/\\\\\\","/ \\\\/ \\ /","\\\\/\\ /  \\"," \\/ /   \\","\\\\\\/  \\\\ ","\\\\\\ \\//  "
    });
  return 0;
}