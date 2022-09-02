//
// Created by Islam, Abdullah Al Raqibul on 02/19/22.
//

class Solution {
public:
  int minimumDeviation(vector<int>& nums) {
    set<int> s;
    for(auto n: nums) {
      if(n%2) s.insert(n * 2);
      else s.insert(n);
    }

    int ret = INT_MAX, curMax;
    while(s.size()) {
      curMax = *s.rbegin();
      ret = min(ret, curMax - *s.begin());

      if(curMax % 2) break;

      s.erase(curMax);
      s.insert(curMax/2);
    }

    return ret;
  }
};