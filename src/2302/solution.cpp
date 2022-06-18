//
// Created by Islam, Abdullah Al Raqibul on 06/17/22.
//

class Solution {
public:
  long long countSubarrays(vector<int>& nums, long long k) {
    long long sum = 0, res = 0;
    for (int r = 0, l = 0; r < nums.size(); r+=1) {
      sum += nums[r];
      while(sum * (r - l + 1) >= k) {
        sum -= nums[l];
        l += 1;
      }
      res += r - l + 1;
    }
    return res;
  }
};