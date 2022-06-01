//
// Created by Islam, Abdullah Al Raqibul on 05/31/22.
//

#define MAX 10005

struct disjoint_set {
  int parent, rank;
};

class Solution {
public:
  vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
    init_dsd(n);
    vector<bool> ret;

    for(int i=threshold+1; i<=n/2; i+=1) {
      if(dset[i].parent == i) {
        for(int j=i+i; j<=n; j+=i) {
          union_by_rank(i, j);
        }
      }
    }

    for(int i=1; i<=n; i+=1) find_set(i);

    for(vector<int> q : queries) {
      int u = find_set(q[0]);
      int v = find_set(q[1]);

      if(u == v) ret.push_back(true);
      else ret.push_back(false);
    }
    return ret;
  }

private:
  struct disjoint_set dset[MAX];

  void init_dsd(int n) {
    for(int i=0; i<=n; i+=1) {
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
    int px = find_set(x);
    int py = find_set(y);

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
  }
};