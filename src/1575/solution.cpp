//
// Created by Islam, Abdullah Al Raqibul on 07/18/22.
//

const long long MOD = (1e9 + 7);

class Solution {
private:
  int do_dp(vector<int>& loc, int curr, int nd, int f, vector<vector<int>>& dp) {
    if(f < 0) return 0;
    if(dp[curr][f] != -1) return dp[curr][f];

    long long ret = (curr == nd) ? 1 : 0;
    int sz = loc.size();
    for(int i=0; i<sz; i+=1) {
      if(i == curr) continue;
      ret = (ret + do_dp(loc, i, nd, f-abs(loc[curr]-loc[i]), dp)) % MOD;
    }

    return dp[curr][f] = ret;
  }

public:
  int countRoutes(vector<int>& loc, int st, int nd, int f) {
    vector<vector<int>> dp(loc.size(), vector<int>(f+1, -1));
    return do_dp(loc, st, nd, f, dp);
  }
};