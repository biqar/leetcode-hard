//
// Created by Islam, Abdullah Al Raqibul on 01/29/22.
//

class Solution {
public:
  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size() , max_area = INT_MIN , i = 0;
    stack<int> s;
    while(i < n) {
      if(s.empty() || nums[s.top()] <= nums[i]) {
        s.push(i);
        i++;
      } else {
        int prev_top = s.top();
        s.pop();
        if(i-1 >= k) {
          max_area = max(max_area , nums[prev_top] * (s.empty() ? i : (s.top() >= k ? 0 : (i - s.top() - 1))));
        }
      }
    }
    while(!s.empty()) {
      int prev_top = s.top();
      s.pop();
      if(i-1 >= k) {
        max_area = max(max_area , nums[prev_top] * (s.empty() ? i : (s.top() >= k ? 0 : (i - s.top() - 1))));
      }
    }
    return max_area;
  }
};