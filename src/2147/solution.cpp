//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int numberOfWays(string corridor) {
    vector<int> pos;
    for(int i=0; i<corridor.length(); i+=1) {
      if(corridor[i] == 'S') pos.push_back(i);
    }

    if(pos.size()%2 || !pos.size()) return 0;

    int mod = (1e9 + 7);
    long long int ret = 1;
    for(int i=2; i<pos.size(); i+=2) {
      ret *= (pos[i]-pos[i-1]);
      ret %= mod;
    }
    return ret;
  }
};