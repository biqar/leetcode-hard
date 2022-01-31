//
// Created by Islam, Abdullah Al Raqibul on 01/31/22.
//

class Solution {
public:
  int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    n = graph.size();
    int sz = initial.size(), maxSegSz = 0, ret = -1;

    init_dsd();
    for(int i=0; i<n; i+=1) {
      for(int j=i+1; j<n; j+=1) {
        if(graph[i][j]) union_by_rank(i, j);
      }
    }

    set_segments(initial, sz);
    sort(initial.begin(), initial.end());
    for(int i=0; i<sz; i+=1) {
      //cout << initial[i] << " " << dset[initial[i]].parent << " " << initial_color[dset[initial[i]].parent] << " " << color[dset[initial[i]].parent] << endl;
      if(initial_color[dset[initial[i]].parent] == 1) {
        if(color[dset[initial[i]].parent] > maxSegSz) {
          maxSegSz = color[dset[initial[i]].parent];
          ret = initial[i];
        }
      }
    }

    return ret == -1 ? initial[0] : ret;
  }

private:
  struct disjoint_set {
    int parent, rank;
  };

  int n;
  int color[305], initial_color[305];
  struct disjoint_set dset[305];

  void init_dsd() {
    for(int i=0; i<n; i+=1) {
      dset[i].parent = i;
      dset[i].rank = 0;

      color[i] = 0;
      initial_color[i] = 0;
    }
  }

  /*find root of the disjoint set with path compression*/
  int find_set(int x) {
    if(x != dset[x].parent) dset[x].parent = find_set(dset[x].parent);
    return dset[x].parent;
  }

  void compress() {
    for(int i=0; i<n; i+=1) find_set(i);
  }

  int find_seg_size(int x) {
    int px = find_set(x), ret = 0;
    for(int i=0; i<n; i+=1) {
      if(dset[i].parent == px) ret += 1;
    }

    return ret;
  }

  void set_segments(vector<int>& initial, int sz) {
    compress();
    for(int i=0; i<n; i+=1) {
      color[dset[i].parent] += 1;
    }

    for(int i=0; i<sz; i+=1) {
      initial_color[dset[initial[i]].parent] += 1;
    }
  }

  /*union disjoint sets by rank*/
  void union_by_rank(int x, int y) {
    int px = find_set(x), py = find_set(y);
    if(px == py) return;

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