//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> goal;
    unordered_map<char, int> curr;
    int curr_len = 0, goal_len = t.length();

    for(char ch : t) {
      goal[ch] += 1;
    }

    int left = 0, right = 0, len = s.length();
    int min_len = len + 1;
    string ret = "";

    for(right = 0; right < len; right += 1) {
      curr[s[right]] += 1;

      if(goal.find(s[right]) == goal.end()) {
        continue;
      }

      if(goal[s[right]] >= curr[s[right]]) curr_len += 1;

      if(curr_len == goal_len) {
        while(goal.find(s[left]) == goal.end() || goal[s[left]] < curr[s[left]]) {
          if(goal.find(s[left]) != goal.end()) curr[s[left]] -= 1;
          left += 1;
        }

        if(right-left+1 < min_len) {
          min_len = right-left+1;
          ret = s.substr(left, min_len);
        }
      }
    }

    return ret;
  }
};