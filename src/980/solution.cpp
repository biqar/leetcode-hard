//
// Created by Islam, Abdullah Al Raqibul on 02/01/22.
//

class Solution {
private:
  int r, c, num_free;
  int dir_r[4] = {0, 0, +1, -1};
  int dir_c[4] = {+1, -1, 0, 0};

  void backtrack(int x, int y, int remain, int &cnt, vector<vector<int>>& grid) {
    if(grid[x][y] == 2) {
      if(remain == 1) cnt += 1;
      return;
    }

    int tmp = grid[x][y], new_x, new_y;
    grid[x][y] = -2;
    for(int i=0; i<4; i+=1) {
      new_x = x + dir_r[i];
      new_y = y + dir_c[i];

      if(new_x < 0 || new_x >= r
         || new_y < 0 || new_y >= c
         || grid[new_x][new_y] < 0) continue;

      backtrack(new_x, new_y, remain-1, cnt, grid);
    }
    grid[x][y] = tmp;
  }

public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int st_r, st_c, path = 0;
    r = grid.size();
    c = grid[0].size();
    num_free = 0;

    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        if(grid[i][j] == 1) {
          st_r = i;
          st_c = j;
        }
        if(grid[i][j] >= 0) {
          num_free += 1;
        }
      }
    }

    backtrack(st_r, st_c, num_free, path, grid);
    return path;
  }
};