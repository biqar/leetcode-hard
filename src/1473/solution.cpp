//
// Created by Islam, Abdullah Al Raqibul on 02/04/22.
//

class Solution {
public:
  const int INF = (1 << 30);
  int dp[101][21][101];
  int vis[101][21][101];

  int _min(int a, int b) {
    return a < b ? a : b;
  }

  int func(int curr_poss, int prev_color, int neigh,
           vector<int>& houses, vector<vector<int>>& cost,
           int m, int n, int target) {
    // basecase, we got more neighbors than `target`
    if(neigh > target) return INF;

    // basecase, we colored all the houses
    if(curr_poss == m) {
      return neigh == target ? 0 : INF;
    }

    // we previously visited this step -- called from overlapping subproblems
    if(vis[curr_poss][prev_color][neigh]) return dp[curr_poss][prev_color][neigh];

    // this house is already been colored, we can't choose a color for it
    if(houses[curr_poss] != 0) {
      return func(curr_poss+1, houses[curr_poss], neigh + (prev_color != houses[curr_poss]),
                  houses, cost, m, n, target);
    }

    int ret = INF;
    for(int col=1; col<=n; col+=1) {
      int tmp = cost[curr_poss][col-1] + func(curr_poss+1, col, neigh + (prev_color != col),
                                              houses, cost, m, n, target);
      ret = _min(ret, tmp);
    }
    vis[curr_poss][prev_color][neigh] = 1;
    return dp[curr_poss][prev_color][neigh] = ret;
  }

  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    // for(int i=0; i<=m; i+=1) {
    //     for(int j=0; j<=n; j+=1) {
    //         for(int k=0; k<=target; k+=1) {
    //             dp[i][j][k] = INF;
    //         }
    //     }
    // }

    memset(vis, 0, sizeof(vis));

    int ret = func(0, 0, 0, houses, cost, m, n, target);
    return ret >= INF ? -1 : ret;
  }
};