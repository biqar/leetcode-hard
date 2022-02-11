//
// Created by Islam, Abdullah Al Raqibul on 02/10/22.
//

class Solution {
public:
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    int mod = 1e9 + 7;
    int sz1 = nums1.size(), sz2 = nums2.size();
    long long  sum1 = 0, sum2 = 0;
    int pos1 = 0, pos2 = 0;
    long long ret = 0;

    while(pos1 < sz1 && pos2 < sz2) {
      if(nums1[pos1] < nums2[pos2]) sum1 += nums1[pos1++];
      else if(nums1[pos1] > nums2[pos2]) sum2 += nums2[pos2++];
      else {
        ret += max(sum1, sum2) + nums1[pos1];
        pos1 += 1;
        pos2 += 1;
        sum1 = sum2 = 0;
      }
    }

    while(pos1 < sz1) sum1 += nums1[pos1++];
    while(pos2 < sz2) sum2 += nums2[pos2++];

    return (ret + max(sum1, sum2)) % mod;
  }
};