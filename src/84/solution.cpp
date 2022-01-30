//
// Created by Islam, Abdullah Al Raqibul on 01/29/22.
//

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = heights.size() , max_area = INT_MIN , i = 0;
    stack<int> s;
    while(i < n) {
      if(s.empty() || heights[s.top()] <= heights[i]) {
        s.push(i);
        i++;
      } else {
        int prev_top = s.top();
        s.pop();
        max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1));
      }
    }
    while(!s.empty()) {
      int prev_top = s.top();
      s.pop();
      max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1));
    }
    return max_area;
  }
};