//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int count_ones(int n) {
    int ret = 0;
    while(n) {
      if(n & 1) ret += 1;
      n >>= 1;
    }

    return ret;
  }

  bool is_set(int n, int pos) {
    return (n & (1 << pos));
  }

  bool dfs(int u, vector<vector<int>>& s, int mask, vector<int> &vis) {
    //cout << mask << endl;
    vis[u] = 1;
    //if(!is_set(mask, u)) return true;
    for(int i=0; i<s.size(); i+=1) {
      if(i == u || s[u][i] == 2) continue;
      //if(vis[i]) continue;

      if(s[u][i] == 0) {
        if(is_set(mask, u)) {
          if(is_set(mask, i)) return false;
          else {
            if(!vis[i]) {
              if(!dfs(i, s, mask, vis)) return false;
            }
          }
        }
      }

      if(s[u][i] == 1) {
        if(is_set(mask, u)) {
          if(!is_set(mask, i)) return false;
          else {
            if(!vis[i]) {
              if(!dfs(i, s, mask, vis)) return false;
            }
          }
        }
      }
    }

    return true;
  }

  bool is_valid(int mask, vector<vector<int>>& s) {
    vector<int> vis(s.size(), 0);

    for(int i=0; i<s.size(); i+=1) {
      if(!vis[i]) {
        if(!dfs(i, s, mask, vis)) return false;
      }
    }
    return true;
  }

  int maximumGood(vector<vector<int>>& s) {
    int n = s.size();
    int ret = 0;

    for(int i=0; i<(1 << n); i+=1) {
      if(is_valid(i, s)) {
        //cout << "valid: " << i << "(" << count_ones(i) << ")" << endl;
        ret = max(ret, count_ones(i));
      }
    }

    //cout << endl;
    return ret;
  }
};