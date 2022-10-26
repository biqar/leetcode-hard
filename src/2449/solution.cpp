//
// Created by Islam, Abdullah Al Raqibul on 10/26/22.
//

class Solution {
public:
  long long makeSimilar(vector<int>& nums, vector<int>& target) {
    vector<vector<int>> nv(2), tv(2);
    for(int n : nums) nv[n % 2].push_back(n);
    for(int t : target) tv[t % 2].push_back(t);

    sort(nv[0].begin(), nv[0].end());
    sort(nv[1].begin(), nv[1].end());
    sort(tv[0].begin(), tv[0].end());
    sort(tv[1].begin(), tv[1].end());

    long long ret = 0;
    for(int i=0; i<nv[0].size(); i+=1) ret += (abs(nv[0][i] - tv[0][i]) / 2);
    for(int i=0; i<nv[1].size(); i+=1) ret += (abs(nv[1][i] - tv[1][i]) / 2);

    return (ret / 2);
  }
};