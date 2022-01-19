//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 1;

    for (int i = 0; i < n; i++) {
      // when the ith element is not i
      while (nums[i] != i + 1) {
        // no need to swap when ith element is out of range [0,n]
        if (nums[i] <= 0 || nums[i] > n) break;

        //handle duplicate elements
        if (nums[i] == nums[nums[i] - 1]) break;

        // swap elements
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] != i + 1) return i + 1;
    }

    return n + 1;
  }
};