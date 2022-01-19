//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, int> m;
    int sz = wordDict.size(), len = s.length();
    vector<vector<int>> dp(len+1);
    vector<bool> vis(len+1, false);
    vector<string> ret;
    vector<int> tmp;

    for(int i=0; i<sz; i+=1) {
      m[wordDict[i]] = i;
    }

    vis[0] = true;
    for(int i=0; i<len; i+=1) {
      if(vis[i] == false) continue;
      for(int j=1; i+j<=len; j+=1) {
        string subStr = s.substr(i, j);
        if(m.find(subStr) != m.end()) {
          vis[i+j] = true;
          dp[i+j].push_back(m[subStr]);
        }
      }
    }

    if(vis[len] == false) return ret;
    dfs(dp, wordDict, ret, tmp, len);

    return ret;
  }

  void dfs(vector<vector<int>>& dp,
           vector<string>& wordDict,
           vector<string>& ret,
           vector<int> &tmp,
           int pos) {
    if(pos == 0) {
      int sz = tmp.size();
      string str = wordDict[tmp[sz-1]];
      for(int i=sz-2; i>=0; i-=1) {
        str += (" " + wordDict[tmp[i]]);
      }
      ret.push_back(str);
      return;
    }

    int sz = dp[pos].size();
    for(int i=0; i<sz; i+=1) {
      tmp.push_back(dp[pos][i]);
      dfs(dp, wordDict, ret, tmp, pos-wordDict[dp[pos][i]].length());
      tmp.pop_back();
    }
  }
};