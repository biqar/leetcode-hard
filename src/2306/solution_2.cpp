//
// Created by Islam, Abdullah Al Raqibul on 06/17/22.
//

// approach-2
class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    unordered_map<string, int> mp;

    for(string idea : ideas) {
      mp[idea] += 1;
    }

    vector<vector<int>> vec(26, vector<int>(26, 0));
    for(string idea : ideas) {
      int i = idea[0] - 'a';
      for(int j=0; j<26; j+=1) {
        idea[0] = ('a' + j);

        if(mp.find(idea) == mp.end()) {
          vec[i][j] += 1;
        }
      }
    }

    long long ret = 0;
    for(int i=0; i<26; i+=1) {
      for(int j=0; j<26; j+=1) {
        ret += (vec[i][j] * vec[j][i]);
      }
    }

    return ret;
  }
};