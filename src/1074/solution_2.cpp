//
// Created by Islam, Abdullah Al Raqibul on 07/18/22.
//

// without extra space
class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int r = matrix.size();
    int c = matrix[0].size();

    // prefix sum
    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        if(i != 0) matrix[i][j] += matrix[i-1][j];
        if(j != 0) matrix[i][j] += matrix[i][j-1];
        if(i && j) matrix[i][j] -= matrix[i-1][j-1];
      }
    }

    int ret = 0, key;
    map<int, int> mp;

    for(int r1=0; r1<r; r1+=1) {
      for(int r2=r1; r2<r; r2+=1) {
        mp.clear();
        mp[0] = 1;

        for(int j=0; j<c; j+=1) {
          if(r1) key = matrix[r2][j] - matrix[r1-1][j];
          else key = matrix[r2][j];
          ret += mp[key - target];
          mp[key] += 1;
        }
      }
    }

    return ret;
  }
};