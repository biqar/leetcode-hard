//
// Created by Islam, Abdullah Al Raqibul on 01/23/22.
//

class Solution {
public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long l = 0, h = accumulate(begin(batteries), end(batteries), 0LL)/n + 1, m, ret = 0, sum;
    while(l < h) {
      m = l + (h-l)/2;
      //cout << l << " " << h << " " << m << endl;
      // m = (l + h + 1) / 2;
      sum = 0;
      for(int i : batteries) sum += min(m, (long long) i);

      if(sum >= n*m) {
        ret = m;
        l = m + 1;
      }
      else h = m;
    }
    return ret;
  }
};