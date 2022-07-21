//
// Created by Islam, Abdullah Al Raqibul on 07/20/22.
//

#define MOD (long long int) (1e9 + 7)

class Solution {
public:
  bool is_valid(int i, int j) {
    if(i>=0 && i<r && j>=0 && j<c) return true;
    return false;
  }

  int func(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& grid) {
    if(dp[i][j] != -1) return dp[i][j];

    long long int ret = 1;
    int ii, jj;
    for(auto d : dir) {
      ii = i + d.first;
      jj = j + d.second;

      if(is_valid(ii, jj) && grid[ii][jj] > grid[i][j]) {
        ret += func(ii, jj, dp, grid);
        ret %= MOD;
      }
    }

    return dp[i][j] = ret;
  }

  int countPaths(vector<vector<int>>& grid) {
    r = grid.size();
    c = grid[0].size();

    vector<vector<int>> dp(r, vector<int>(c, -1));
    long long int ret = 0;

    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        ret += func(i, j, dp, grid);
        ret %= MOD;
      }
    }

    return ret;
  }

private:
  int r, c;
  vector<pair<int, int>> dir = {{0,1}, {-1,0}, {1,0}, {0,-1}};
};