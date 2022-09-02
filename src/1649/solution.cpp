//
// Created by Islam, Abdullah Al Raqibul on 01/11/21.
//

class Solution {
public:
  const int MOD = 1000000007;

  class BIT {
    int *tree;
    int m;

  public:
    BIT(int sz) {
      tree = (int *) malloc(sz * sizeof(int));
      memset(tree, 0, sz * sizeof(int));
      m = sz;
    }

    void add(int index, int value) {
      while (index < m) {
        tree[index] += value;
        index += index & -index;
      }
    }

    int query(int index) {
      int ret = 0;
      while (index > 0) {
        ret += tree[index];
        index -= index & -index;
      }
      return ret;
    }
  };

  int createSortedArray(vector<int>& ins) {
    int ret = 0, sz = ins.size(), hight = 0;

    for (int i=0; i<sz; i+=1) hight = max(hight, ins[i]);
    BIT tree(hight+1);

    for (int i=0; i<sz; i+=1) {
      int leftCost = tree.query(ins[i] - 1);
      int rightCost = i - tree.query(ins[i]);
      ret += min(leftCost, rightCost);
      if(ret > MOD) ret %= MOD;
      tree.add(ins[i], 1);
    }

    return ret;
  }
};