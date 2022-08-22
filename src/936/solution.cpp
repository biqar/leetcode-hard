//
// Created by Islam, Abdullah Al Raqibul on 08/21/22.
//

class Solution {
public:
  bool match(string &t, string &s, int st) {
    for(int i=0; i<s.size(); i+=1) {
      if(t[st+i] != '*' && t[st+i] != s[i]) return false;
    }
    return true;
  }

  void do_stamp(string &t, int st, int nd, int &itr) {
    for(int i=st; i<nd; i+=1) {
      if(t[i] != '*') {
        itr += 1;
        t[i] = '*';
      }
    }
  }

  vector<int> movesToStamp(string stamp, string target) {
    int n = target.size(), ssz = stamp.size();
    vector<int> ret, vis(n, 0);
    int itr = 0;
    bool did_stamp;

    while(itr < n) {
      did_stamp = false;
      for(int i=0; i<=n-ssz; i+=1) {
        if(!vis[i] && match(target, stamp, i)) {
          vis[i] = 1;
          ret.push_back(i);
          do_stamp(target, i, i+ssz, itr);
          did_stamp = true;
          if(itr == n) break;
        }
      }

      if(!did_stamp) return vector<int>{};
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
};