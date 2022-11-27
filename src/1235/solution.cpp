//
// Created by Islam, Abdullah Al Raqibul on 11/26/22.
//

class Solution {
public:
  int func(vector<vector<int>>& vec, vector<int>& dp, int pos, int lasttime) {
    if(pos >= vec.size()) return 0;
    if(vec[pos][0] < lasttime) return func(vec, dp, pos + 1, lasttime);
    if(dp[pos] != -1) return dp[pos];
    return dp[pos] = max(func(vec, dp, pos+1, vec[pos][1]) + vec[pos][2], func(vec, dp, pos+1, lasttime));
  }

  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    vector<vector<int>> vec;

    for(int i=0; i<startTime.size(); i+=1) vec.push_back({startTime[i], endTime[i], profit[i]});
    sort(vec.begin(), vec.end());
    vector<int> dp(startTime.size()+1, -1);
    return func(vec, dp, 0, 0);
  }
};