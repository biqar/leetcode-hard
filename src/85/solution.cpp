//
// Created by Islam, Abdullah Al Raqibul on 01/29/22.
//

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    int r = matrix.size(), c = matrix[0].size(), max_area = INT_MIN;
    vector<int> heights(c, 0);

    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        if(matrix[i][j] == '1') heights[j] += 1;
        else heights[j] = 0;
      }

      max_area = max(max_area, largestRectangleArea__leetcode84(heights)) ;
    }

    return max_area;
  }

  int largestRectangleArea__leetcode84(vector<int>& heights) {
    int n = heights.size() , max_area = INT_MIN , i = 0 ;
    stack<int> s ;
    while(i < n) {
      if(s.empty() || heights[s.top()] <= heights[i]) {
        s.push(i) ;
        i++ ;
      } else {
        int prev_top = s.top() ;
        s.pop() ;
        max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
      }
    }
    while(!s.empty()) {
      int prev_top = s.top() ;
      s.pop() ;
      max_area = max(max_area , heights[prev_top] * (s.empty() ? i : i - s.top() - 1)) ;
    }
    return max_area ;
  }
};