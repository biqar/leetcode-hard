//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

#define MAX 100005
#define ALL 3
#define BOB 2
#define ALICE 1

class Solution {
private:
  struct disjoint_set {
    int parent, rank;
  };

  struct disjoint_set a[MAX], b[MAX];

  void init_dsd(int nodes) {
    for(int i=0; i<nodes; i+=1) {
      a[i].parent = i;
      a[i].rank = 0;

      b[i].parent = i;
      b[i].rank = 0;
    }
  }

  /*find root of the disjoint set with path compression*/
  int find_set_a(int x) {
    if(x != a[x].parent) a[x].parent = find_set_a(a[x].parent);
    return a[x].parent;
  }

  int find_set_b(int x) {
    if(x != b[x].parent) b[x].parent = find_set_b(b[x].parent);
    return b[x].parent;
  }

  /*union disjoint sets by rank*/
  void union_by_rank_a(int px, int py) {
    if(a[px].rank < a[py].rank) {
      a[px].parent = py;
    }
    else if(a[px].rank > a[py].rank) {
      a[py].parent = px;
    }
    else {
      a[py].parent = px;
      a[px].rank += 1;
    }
  }

  void union_by_rank_b(int px, int py) {
    if(b[px].rank < b[py].rank) {
      b[px].parent = py;
    }
    else if(b[px].rank > b[py].rank) {
      b[py].parent = px;
    }
    else {
      b[py].parent = px;
      b[px].rank += 1;
    }
  }

  static bool comp(const vector<int> &lft, const vector<int> &rgt) {
    if(lft[0] != rgt[0]) return lft[0] > rgt[0];
    return false;
  }

  bool is_traversable(int nodes) {
    for(int i=0; i<nodes; i+=1) {
      if(a[i].parent != a[0].parent) return false;
      if(b[i].parent != b[0].parent) return false;
    }
    return true;
  }

  void print_a(int nodes) {
    for(int i=0; i<nodes; i+=1) cout << a[i].parent << " ";
    cout << endl;
  }

  void print_b(int nodes) {
    for(int i=0; i<nodes; i+=1) cout << b[i].parent << " ";
    cout << endl;
  }

public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int ret = 0;
    int num_edge = edges.size();
    sort(edges.begin(), edges.end(), comp);
    int u, v, pua, pub, pva, pvb;
    vector<vector<int>> conflict;

    //unordered_map<pair<int, int>, bool > ma;
    //unordered_map<pair<int, int>, bool > mb;

    init_dsd(n);

//         for(int i=0; i<num_edge; i+=1) {
//             u = edges[i][1] - 1;
//             v = edges[i][2] - 1;

//             if(edges[i][0] == ALICE) {
//                 if(u < v) ma[make_pair(u, v)] = true;
//                 else ma[make_pair(v, u)] = true;
//             }
//             if(edges[i][0] == BOB) {
//                 if(u < v) mb[make_pair(u, v)] = true;
//                 else mb[make_pair(v, u)] = true;
//             }
//         }

    //for(int i=0; i<num_edge; i+=1) cout << edges[i][0] << " " << edges[i][1] << " " << edges[i][2] << endl;
    //cout << endl;

    for(int i=0; i<num_edge; i+=1) {
      u = edges[i][1] - 1;
      v = edges[i][2] - 1;

      if(edges[i][0] == ALL) {
        pua = find_set_a(u);
        pva = find_set_a(v);

        pub = find_set_b(u);
        pvb = find_set_b(v);

        //cout << ALL << " " << u+1 << " " << v+1 << endl;
        //cout << pua << " " << pva << " " << pub << " " << pvb << endl;

        if(pua == pva && pub == pvb) {
          //cout << ALL << " " << u+1 << " " << v+1 << endl;
          ret += 1;
          continue;
        }

        if(pua != pva && pub != pvb) {
          union_by_rank_a(pua, pva);
          union_by_rank_b(pub, pvb);
        }
        else {
          conflict.push_back(edges[i]);
        }
        // else if(pua != pva) {
        //     // alice may need this edge
        // }
        // else if(pub != pvb) {
        //     // bob may need this edge
        // }
      }
      else if(edges[i][0] == ALICE) {
        pua = find_set_a(u);
        pva = find_set_a(v);

        if(pua == pva) {
          //cout << ALICE << " " << u+1 << " " << v+1 << endl;
          ret += 1;
        }
        else {
          union_by_rank_a(pua, pva);
        }
      }
      else {
        pub = find_set_b(u);
        pvb = find_set_b(v);

        if(pub == pvb) {
          //cout << BOB << " " << u+1 << " " << v+1 << endl;
          ret += 1;
        }
        else {
          union_by_rank_b(pub, pvb);
        }
      }
    }

    int num_con = conflict.size();
    //cout << num_con << endl;
    for(int i=0; i<num_con; i+=1) {
      u = conflict[i][1] - 1;
      v = conflict[i][2] - 1;

      pua = find_set_a(u);
      pva = find_set_a(v);

      pub = find_set_b(u);
      pvb = find_set_b(v);

      if(pua == pva && pub == pvb) {
        //cout << ALL << " " << u+1 << " " << v+1 << endl;
        ret += 1;
        continue;
      }

      if(pua != pva) {
        union_by_rank_a(pua, pva);
      }
      else {
        union_by_rank_b(pub, pvb);
      }
    }

    for(int i=0; i<n; i+=1) {
      find_set_a(i);
      find_set_b(i);
    }
    //print_a(n);
    //print_b(n);
    if(!is_traversable(n)) return -1;
    return ret;
  }
};