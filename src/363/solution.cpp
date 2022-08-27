//
// Created by Islam, Abdullah Al Raqibul on 08/27/22.
//

class Solution {
public:
  int find_max(vector<int>& csum, int k) {
    int c = csum.size();
    int ret = INT_MIN;
    int curr = 0;
    set<int> s;
    s.insert(0);
    for(int i : csum) {
      curr += i;
      auto it = s.lower_bound(curr - k);
      if(it != s.end()) ret = max(ret, curr - *it);
      s.insert(curr);
    }

    return ret;
  }

  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> csum;
    int ret = INT_MIN;

    for(int sr=0; sr<r; sr+=1) {
      csum.assign(c, 0);
      for(int er=sr; er<r; er+=1) {
        for(int j=0; j<c; j+=1) {
          csum[j] += matrix[er][j];
        }
        ret = max(ret, find_max(csum, k));
      }
    }

    return ret;
  }
};