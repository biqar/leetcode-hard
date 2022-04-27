//
// Created by Islam, Abdullah Al Raqibul on 04/27/22.
//

struct disjoint_set {
  int parent, rank;
};

class Solution {
public:
  const static int MAX = 1005;

  vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
    nodes = n;
    //initialize disjoint set data-structure
    init_dsd();

    vector<bool> ret;
    int p0, p1;
    int r0, r1;
    bool flg;
    for(auto p : requests) {
      p0 = find_set(p[0]);
      p1 = find_set(p[1]);

      if(p0 != p1) {
        flg = true;
        for(auto r : restrictions) {
          r0 = find_set(r[0]);
          r1 = find_set(r[1]);

          if((r0 == p0 && r1 == p1) || (r0 == p1 && r1 == p0)) {
            flg = false;
            break;
          }
        }
        ret.push_back(flg);
        if(flg) union_by_rank(p[0], p[1]);
      }
      else ret.push_back(true);
    }

    return ret;
  }

private:
  int nodes;
  struct disjoint_set dset[MAX];

  void init_dsd() {
    for(int i=0; i<nodes; i+=1) {
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