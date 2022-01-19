//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int findMin(vector<int>& nums) {
    int ret = nums[0];
    for(int n : nums) ret = min(ret, n);
    return ret;
  }
};