//
// Created by Islam, Abdullah Al Raqibul on 05/19/22.
//

#define MAX 205
#define pii pair<int, int>

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    r = matrix.size();
    c = matrix[0].size();
    int ret = -1;

    vector<vector<long long int>> dp(MAX, vector<long long int>(MAX, -1));

    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        ret = max(ret, dfs(i, j, matrix, dp));
      }
    }

    return ret;
  }

  int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<long long int>>& dp) {
    if(dp[i][j] != -1) return dp[i][j];

    int ret = 0, ii, jj;
    for(auto d : dir) {
      ii = i + d.first;
      jj = j + d.second;

      if(ii >= 0 && ii < r && jj >= 0 && jj < c) {
        if(matrix[ii][jj] > matrix[i][j]) ret = max(ret, dfs(ii, jj, matrix, dp));
      }
    }

    return dp[i][j] = (ret + 1);
  }

private:
  int r, c;
  vector<pii> dir{pii(0, +1), pii(0, -1), pii(+1, 0), pii(-1, 0)};
};