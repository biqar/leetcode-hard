//
// Created by Islam, Abdullah Al Raqibul on 09/23/22.
//

class Solution {
public:
  vector<int> recoverArray(vector<int>& nums) {
    int sz = nums.size();

    unordered_map<int, int> mmp;
    for(int n : nums) mmp[n] += 1;

    sort(nums.begin(), nums.end());

    for(int i=1; i<sz; i+=1) {
      int kk = nums[i] - nums[0];

      if(kk % 2 || !kk) continue;
      int k = kk / 2;

      unordered_map<int, int> mp = mmp;
      vector<int> ret;

      for(int n : nums) {
        if(mp[n] >= 1) {
          if(mp[n + kk] >= 1) {
            ret.push_back(n + k);
            mp[n] -= 1;
            mp[n + kk] -= 1;
          }
          else break;
        }
      }

      if(ret.size() == sz/2) return ret;
    }

    return vector<int>();
  }
};