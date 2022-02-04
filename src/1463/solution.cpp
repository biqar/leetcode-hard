//
// Created by Islam, Abdullah Al Raqibul on 02/04/22.
//

class Solution {
public:
  int dp[75][75][75];
  int row, col;

  int dfs(int r, int c1, int c2, vector<vector<int>>& grid) {
    if(r == row) return 0;
    if(dp[r][c1][c2] != -1) return dp[r][c1][c2];

    int ret = -1;
    for(int i=-1; i<=1; i+=1) {
      if(c1+i >= 0 && c1+i < col) {
        for(int j=-1; j<=1; j+=1) {
          if(c2+j >= 0 && c2+j < col) {
            ret = max(ret, dfs(r+1, c1+i, c2+j, grid));
          }
        }
      }
    }

    ret += (grid[r][c1] + grid[r][c2]);
    if(c1 == c2) ret -= grid[r][c1];
    return dp[r][c1][c2] = ret;
  }

  int cherryPickup(vector<vector<int>>& grid) {
    memset(dp, -1, sizeof(dp));

    row = grid.size();
    if(row) col = grid[0].size();

    return dfs(0, 0, col-1, grid);
  }
};