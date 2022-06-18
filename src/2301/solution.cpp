//
// Created by Islam, Abdullah Al Raqibul on 06/17/22.
//

class Solution {
public:
  bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
    vector<vector<int>> flg(256, vector<int>(256, 0));
    for(vector<char> pair : mappings) {
      flg[pair[1]][pair[0]] = 1;
    }

    int len = s.length();
    int n = sub.length();
    for(int i=0; i<=len-n; i+=1) {
      if(s[i] == sub[0] || flg[s[i]][sub[0]]) {
        int j;
        for(j=1; j<n; j+=1) {
          if(s[i+j] != sub[j] && !flg[s[i+j]][sub[j]]) break;
        }

        if(j == n) return true;
      }
    }

    return false;
  }
};