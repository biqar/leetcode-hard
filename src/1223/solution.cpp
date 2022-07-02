//
// Created by Islam, Abdullah Al Raqibul on 07/02/22.
//

#define MOD (long long int) (1e9 + 7)

class Solution {
public:
  int func(vector<vector<vector<int>>> &dp, int n, vector<int>& rollMax, int l, int c, int idx) {
    if(idx == n) return 1;
    if(dp[idx][l][c] != -1) return dp[idx][l][c];

    long long int ret = 0;
    for(int i=1; i<7; i+=1) {
      if(i == l) {
        if(c >= rollMax[i-1]) continue;
        ret += func(dp, n, rollMax, i, c+1, idx+1);
      }
      else {
        ret += func(dp, n, rollMax, i, 1, idx+1);
      }

      ret %= MOD;
    }

    return dp[idx][l][c] = ret;
  }

  int dieSimulator(int n, vector<int>& rollMax) {
    int maxCnt = *max_element(rollMax.begin(), rollMax.end());
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(7, vector<int>(maxCnt + 1, -1)));

    return func(dp, n, rollMax, 0, 0, 0);
  }
};