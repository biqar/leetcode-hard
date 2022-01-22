//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  int minSwapsCouples(vector<int>& row) {
    int n = row.size() / 2;
    int a, b, ret = 0;

    init_dsd(n);

    for(int i=0; i<n; i+=1) {
      a = row[2*i];
      b = row[(2*i) + 1];

      union_by_rank(a/2, b/2);
    }

    return (n - seg);
  }

private:
  struct disjoint_set {
    int parent, rank;
  };

  int n, seg;
  struct disjoint_set dset[40];

  void init_dsd(int n) {
    n = seg = n;
    for(int i=0; i<n; i+=1) {
      dset[i].parent = i;
      dset[i].rank = 0;
    }
  }

  /*find root of the disjoint set with path compression*/
  int find_set(int x) {
    if(x != dset[x].parent) dset[x].parent = find_set(dset[x].parent);
    return dset[x].parent;
  }

  /*union disjoint sets by rank*/
  void union_by_rank(int x, int y) {
    int px = find_set(x), py = find_set(y);
    if(px != py) {
      if(dset[px].rank < dset[py].rank) {
        dset[px].parent = py;
      }
      else if(dset[px].rank > dset[py].rank) {
        dset[py].parent = px;
      }
      else {
        dset[py].parent = px;
        dset[px].rank += 1;
      }

      seg -= 1;
    }
  }
};