//
// Created by Islam, Abdullah Al Raqibul on 06/19/22.
//

// inspired by @lympanda's solutiuon in "Weekly Contest 298"

class Solution {
public:
  long long dodp(int m, int n, vector<vector<long long>>& dp, vector<vector<int>>& price) {
    if(dp[m][n] != -1) return dp[m][n];

    long long tmp, ret = 0;
    if(price[m][n] > 0) ret = price[m][n];

    for (int i=1; i<m; i+=1) {
      tmp = dodp(i, n, dp, price) + dodp(m-i, n, dp, price);
      ret = max(tmp, ret);
    }

    for (int i=1; i<n; i+=1) {
      tmp = dodp(m, i, dp, price) + dodp(m, n-i, dp, price);
      ret = max(tmp, ret);
    }

    return dp[m][n] = ret;
  }

  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    vector<vector<int>> price_map(m + 1, vector<int>(n + 1, 0));
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, -1));

    for(auto p : prices) {
      price_map[p[0]][p[1]] = p[2];
    }

    return dodp(m, n, dp, price_map);
  }
};
