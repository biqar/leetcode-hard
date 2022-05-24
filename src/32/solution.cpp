//
// Created by Islam, Abdullah Al Raqibul on 05/24/22.
//

class Solution {
public:
  int longestValidParentheses(string s) {
    int ret = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') st.push(i);
      else {
        st.pop();
        if (st.empty()) st.push(i);
        else ret = max(ret, i - st.top());
      }
    }
    return ret;
  }
};