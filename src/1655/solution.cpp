//
// Created by Islam, Abdullah Al Raqibul on 11/22/20.
//

class Solution {
public:
  bool backtrack(vector<int>& freq, vector<int>& quantity, int idx) {
    if(idx >= quantity.size()) return true;

    for(int i=0; i<freq.size(); i+=1) {
      if(quantity[idx] > freq[i]) continue;

      freq[i] -= quantity[idx];
      if(backtrack(freq, quantity, idx+1)) {
        return true;
      }
      freq[i] += quantity[idx];
    }
    return false;
  }

  bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    int q = 0;
    for(auto _q : quantity) q += _q;
    if(q > nums.size()) return false;

    vector<int> freq;
    unordered_map<int, int> m;
    for(auto _n : nums) m[_n] += 1;
    for(auto it : m) freq.push_back(it.second);

    sort(quantity.begin(), quantity.end(), greater<int>());
    sort(freq.begin(), freq.end(), greater<int>());
    return backtrack(freq, quantity, 0);
  }
};