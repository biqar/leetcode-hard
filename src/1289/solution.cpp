//
// Created by Islam, Abdullah Al Raqibul on 12/13/22.
//

class Solution {
public:
  int func(vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int r, int c) {
    if(r == n) return 0;
    if(dp[r][c] != -1) return dp[r][c];

    int ret = INT_MAX;
    for(int i=0; i<n; i+=1) {
      if(i == c) continue;
      ret = min(ret, func(grid, dp, n, r+1, i) + grid[r][i]);
    }
    return dp[r][c] = ret;
  }

  int minFallingPathSum(vector<vector<int>>& grid) {
    int ret = INT_MAX;
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    for(int i=0; i<n; i+=1) {
      ret = min(ret, func(grid, dp, n, 1, i) + grid[0][i]);
    }
    return ret;
  }
};