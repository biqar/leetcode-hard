//
// Created by Islam, Abdullah Al Raqibul on 08/07/22.
//

class Solution {
public:
  int countVowelPermutation(int n) {
    vector<vector<long long>> dp(n, vector<long long>(5, 0));
    long long mod = (1e9) + 7;
    vector<vector<int>> valid_from = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};

    for(int j=0; j<5; j+=1) dp[0][j] = 1;
    for(int i=1; i<n; i+=1) {
      for(int j=0; j<5; j+=1) {
        for(int k : valid_from[j]) {
          dp[i][j] += dp[i-1][k];
          dp[i][j] %= mod;
        }
      }
    }

    int ret;
    for(int j=0; j<5; j+=1) {
      ret += dp[n-1][j];
      ret %= mod;
    }

    return ret;
  }
};