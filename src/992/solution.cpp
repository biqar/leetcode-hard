//
// Created by Islam, Abdullah Al Raqibul on 06/09/22.
//

class Solution {
public:
  int solve_at_most(vector<int>& nums, int k){
    int n = nums.size();
    int ret = 0;
    int lft = 0, rgt = 0;
    int curr_dist = 0;
    unordered_map<int, int> mp;

    while(rgt < n) {
      mp[nums[rgt]] += 1;
      if(mp[nums[rgt]] == 1) curr_dist += 1;

      while(curr_dist > k){
        mp[nums[lft]] -= 1;
        if(mp[nums[lft]] == 0) curr_dist -= 1;
        lft += 1;
      }
      // cout << "lft: " << lft << ", rgt: " << rgt << ", gap: " << (rgt - lft + 1) << endl;
      ret += (rgt - lft + 1);
      rgt += 1;
    }
    return ret;
  }

  int subarraysWithKDistinct(vector<int>& nums, int k) {
    return solve_at_most(nums, k) - solve_at_most(nums, k - 1);
  }
};