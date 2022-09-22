//
// Created by Islam, Abdullah Al Raqibul on 09/22/22.
//

class Solution {
public:
  long long minimumMoney(vector<vector<int>>& txs) {
    long long currMoney = 0;
    long long ans = 0;

    int lr, rl;
    sort(txs.begin(), txs.end(), [&](const vector<int>& lft, const vector<int>& rgt) {
      lr = min(-lft[0], -lft[0] + lft[1] - rgt[0]); // performing transaction in: lft -> rgt
      rl = min(-rgt[0], -rgt[0] + rgt[1] - lft[0]); // performing transaction in: rgt -> lft
      if(lr == rl) return lft[0] > rgt[0];
      return lr < rl;
    });

    for (vector<int>& ctx : txs) {
      currMoney -= ctx[0];
      ans = min(ans, currMoney);
      currMoney += ctx[1];
    }
    return ans < 0 ? abs(ans) : 0;
  }
};