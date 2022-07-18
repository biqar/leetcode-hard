//
// Created by Islam, Abdullah Al Raqibul on 07/18/22.
//

// with extra space
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<int>> pref(r+1, vector<int>(c+1, 0));

    // prefix sum
    for(int i=1; i<=r; i+=1) {
      for(int j=1; j<=c; j+=1) {
        pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + matrix[i-1][j-1];
      }
    }

    int ret = 0, key;
    map<int, int> mp;

    for(int r1=1; r1<=r; r1+=1) {
      for(int r2=r1; r2<=r; r2+=1) {
        mp.clear();
        mp[0] = 1;

        for(int j=1; j<=c; j+=1) {
          key = pref[r2][j] - pref[r1-1][j];
          ret += mp[key - target];
          mp[key] += 1;
        }
      }
    }

    return ret;
  }
};