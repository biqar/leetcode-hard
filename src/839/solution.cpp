//
// Created by Islam, Abdullah Al Raqibul on 01/25/22.
//

struct disjoint_set {
  int parent, rank;
};

class Solution {
public:
  int numSimilarGroups(vector<string>& A) {
    m.clear();
    n = 0;

    int sz = A.size();
    for(int i=0; i<sz; i+=1) {
      if(m.find(A[i]) == m.end()) {
        id[i] = n;
        m[A[i]] = n;
        n += 1;
      }
      else {
        id[i] = m[A[i]];
      }
    }

    wl = A[0].length();
    init_dsd();
    int u, v, pu, pv;

    if(n < wl*wl) {
      for(int i=0; i<sz; i+=1) {
        for(int j=i+1; j<sz; j+=1) {
          u = id[i];
          v = id[j];
          if(u == v) continue;
          pu = find_set(u);
          pv = find_set(v);

          if(pu != pv) {
            diff.clear();
            for(int k=0; k<wl; k+=1) {
              if(A[i][k] != A[j][k]) {
                diff.push_back(k);
              }
            }

            if(diff.size() == 2 &&
               A[i][diff[0]] == A[j][diff[1]] &&
               A[i][diff[1]] == A[j][diff[0]]) {
              union_by_rank(pu, pv);
            }
          }
        }
      }
    }
    else {
      for(int i=0; i<sz; i+=1) {
        for(int j=0; j<wl; j+=1) {
          for(int k=j+1; k<wl; k+=1) {
            swap(A[i][j], A[i][k]);
            if(m.find(A[i]) != m.end()) {
              u = id[i];
              v = m[A[i]];

              pu = find_set(u);
              pv = find_set(v);

              if(pu != pv) {
                union_by_rank(pu, pv);
              }
            }
            swap(A[i][j], A[i][k]);
          }
        }
      }
    }

    unordered_set<int> s;
    for(int i=0; i<n; i+=1) {
      find_set(i);
      s.insert(dset[i].parent);
    }
    return s.size();
  }
private:
  int n, e, wl;
  map<string, int> m;
  struct disjoint_set dset[2005];
  vector<int> diff;
  int id[2005];

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
  void union_by_rank(int px, int py) {
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

  static bool comp(const disjoint_set &lft, const disjoint_set &rgt) {
    return lft.parent < rgt.parent;
  }
};