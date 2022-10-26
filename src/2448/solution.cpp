//
// Created by Islam, Abdullah Al Raqibul on 10/26/22.
//

class Solution {
public:
  long long getCost(vector<int>& nums, vector<int>& cost, int val) {
    long long ret = 0;
    int len = nums.size();

    for(int i=0; i<len; i+=1) {
      ret += ((long long) abs(nums[i] - val) * cost[i]);
    }
    return ret;
  }

  long long minCost(vector<int>& nums, vector<int>& cost) {
    int hi = *max_element(nums.begin(), nums.end());
    int lo = *min_element(nums.begin(), nums.end());
    int mid;
    long long ret = getCost(nums, cost, lo), cm, cn;

    while(lo < hi) {
      mid = (lo + hi) / 2;

      cm = getCost(nums, cost, mid);
      cn = getCost(nums, cost, mid + 1);

      ret = min(cm, cn);

      if(cm < cn) hi = mid;
      else lo = mid + 1;
    }

    return ret;
  }
};