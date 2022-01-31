//
// Created by Islam, Abdullah Al Raqibul on 01/31/22.
//

struct disjoint_set {
  int parent, rank;
};

#define MAX (100000 + 5)

bool comp(const disjoint_set &a, const disjoint_set &b) {
  if(a.parent == b.parent) return (a.rank < b.rank);
  return (a.parent < b.parent);
}

class Solution {
public:
  int largestComponentSize(vector<int>& nums) {
    n = 0;

    for(int x : nums) n = max(x, n);
    n += 1;
    init_dsd();

    for(int x : nums) {
      for(int i=2; i*i<=x; i+=1) {
        if(x % i == 0) {
          union_by_rank(x, i);
          if(i != x/i) union_by_rank(x, x/i);
        }
      }
    }

    find_ans(nums);
    return max_g;
  }

private:
  int n;
  unordered_map<int, int> m;
  struct disjoint_set dset[MAX];
  int max_g = -1;

  void init_dsd() {
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

  void find_ans(vector<int>& nums) {
    for(int x : nums) {
      find_set(x);
      m[dset[x].parent] += 1;
      max_g = max(max_g, m[dset[x].parent]);
    }
  }
};