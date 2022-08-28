//
// Created by Islam, Abdullah Al Raqibul on 08/27/22.
//

class Solution {
public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    stack<int> s;
    int n = heights.size();
    vector<int> ret(n, 0);

    for(int i=0; i<n; i+=1) {
      if(!s.empty() && heights[s.top()] > heights[i]) {
        ret[s.top()] += 1;
      }
      else {
        while(!s.empty() && heights[s.top()] <= heights[i]) {
          ret[s.top()] += 1;
          s.pop();
        }
        if(!s.empty()) ret[s.top()] += 1;
      }
      s.push(i);
    }

    return ret;
  }
};