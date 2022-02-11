//
// Created by Islam, Abdullah Al Raqibul on 02/10/22.
//

class Solution {
public:
  bool recur(int n, vector<int> &dp) {
    if(n <= 0) return false;
    if(dp[n] != -1) return dp[n];

    for(int i=1; i*i<=n; i+=1) {
      int ret = recur(n-(i*i), dp);
      if(!ret) return dp[n] = 1;
    }
    return dp[n] = 0;
  }

  bool winnerSquareGame(int n) {
    vector<int> dp(max(n+1,3), -1);
    dp[1] = 1;
    dp[2] = 0;

    return recur(n, dp);
  }
};