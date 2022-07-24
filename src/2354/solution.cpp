//
// Created by Islam, Abdullah Al Raqibul on 07/24/22.
//

class Solution {
public:
  int num_set_bits(int n) {
    int ret = 0;
    while(n) {
      ret += (n & 1);
      n >>= 1;
    }
    return ret;
  }

  long long countExcellentPairs(vector<int>& nums, int k) {
    set<int> s;

    for(int i : nums) s.insert(i);
    nums.clear();
    for(int i : s) nums.push_back(num_set_bits(i));

    int n = nums.size();
    sort(nums.begin(), nums.end());
    int r = n - 1;
    long long  ret = 0;
    for(int l=0; l<n; l+=1) {
      if(nums[l] + nums[r] < k) continue;
      while(r >= 0 && nums[l] + nums[r] >= k) r -= 1;
      r += 1;
      ret += (n - r);
    }

    return ret;
  }
};