//
// Created by Islam, Abdullah Al Raqibul on 07/02/22.
//

#define MOD (long long int) (1e9 + 7)

class Solution {
public:
  int func(vector<vector<vector<int>>> &dp, int n, int l, int ll, int idx) {
    if(idx == n) return 1;
    if(dp[idx][l][ll] != -1) return dp[idx][l][ll];

    long long int ret = 0;
    for(int i=1; i<7; i+=1) {
      if(i == l) continue;
      if(i == ll) continue;
      if(l && __gcd(i, l) > 1) continue;

      ret += func(dp, n, i, l, idx+1);
      ret %= MOD;
    }

    return dp[idx][l][ll] = ret;
  }

  int distinctSequences(int n) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(7, -1)));

    return func(dp, n, 0, 0, 0);
  }
};