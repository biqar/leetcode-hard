//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& grid) {
    int c, r = grid.size();
    if(r != 0) c = grid[0].size();
    else return 0;

    vector<vector<int>> dp(r, vector<int>(c, 0));

    for(int i=r-1; i>=0; i-=1) {
      for(int j=c-1; j>=0; j-=1) {
        if(i==r-1 && j==c-1) dp[i][j] = max(1, 1-grid[i][j]);

        else if(i==r-1) dp[i][j] = max(1, dp[i][j+1] - grid[i][j]);

        else if(j==c-1) dp[i][j] = max(1, dp[i+1][j] - grid[i][j]);

        else {
          dp[i][j] = max(1, min(dp[i][j+1], dp[i+1][j])-grid[i][j]);
        }
      }
    }

    return dp[0][0];
  }
};