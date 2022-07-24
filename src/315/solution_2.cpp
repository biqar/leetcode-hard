//
// Created by Islam, Abdullah Al Raqibul on 05/19/22.
//

// Solution of user @Mikerufy: https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/2320285/Policy-Based-Data-Structure(Ordered-Set)-C%2B%2B

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> ans(nums.size(),0);
    ordered_set s;
    for(int i=nums.size()-1;i>=0;i--){
      s.insert(nums[i]);
      ans[i] = s.order_of_key(nums[i]);
    }
    return ans;
  }
};