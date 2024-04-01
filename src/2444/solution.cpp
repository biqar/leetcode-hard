//
// Created by Islam, Abdullah Al Raqibul on 03/31/24.
//

class Solution {
public:
  long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int mx = -1, mn = -1;
    int lft = 0;
    long long ret = 0;
    for(int i=0; i<nums.size(); i+=1) {
      if(nums[i] < minK || nums[i] > maxK) {
        lft = i+1;
        continue;
      }
      if(nums[i] == minK) mn = i;
      if(nums[i] == maxK) mx = i;
      ret += (max(min(mn, mx)-lft+1, 0));
    }
    return ret;
  }
};