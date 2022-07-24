//
// Created by Islam, Abdullah Al Raqibul on 05/19/22.
//

#define MAXN 20005
#define BASE 10000

class Solution {
public:
  inline int transform(int i) {
    return (i + BASE);
  }

  int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) return t[v];

    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
  }

  void update(int v, int tl, int tr, int pos, int adjust) {
    if (tl == tr) {
      t[v] += adjust;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v*2, tl, tm, pos, adjust);
      else
        update(v*2+1, tm+1, tr, pos, adjust);
      t[v] = t[v*2] + t[v*2+1];
    }
  }

  vector<int> countSmaller(vector<int>& nums) {
    sz = nums.size();
    n = (MAXN - 1);
    memset(t, 0, (4*MAXN)*(sizeof(int)));
    vector<int> ret(sz);

    for(int i=0; i<sz; i+=1) {
      nums[i] = transform(nums[i]);
      update(1, 0, n, nums[i], 1);
    }

    for(int i=0; i<sz; i+=1) {
      ret[i] = sum(1, 0, n, 0, nums[i]-1);
      update(1, 0, n, nums[i], -1);
    }

    return ret;
  }

private:
  int sz, n, t[4*MAXN];
};