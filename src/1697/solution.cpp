//
// Created by Islam, Abdullah Al Raqibul on 12/21/20.
//

#define MAX 100005
#define pii pair< int, int >
#define ff first
#define ss second

class Solution {
public:
  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
    init(n, edgeList, queries);
    vector<bool> ret(qsz, false);

    int u, v, pu, pv;
    for(int i=0; i<qsz; i+=1) {
      peocess(q_list[i].ff.ff);

      u = q_list[i].ss.ff;
      v = q_list[i].ss.ss;

      pu = find_set(u);
      pv = find_set(v);

      /*u and v are in same set, so there is a path between this two nodes*/
      if(pu == pv) {
        ret[q_list[i].ff.ss] = true;
      }
    }

    return ret;
  }

private:
  struct disjoint_set {
    int parent, rank;
  };

  int qsz, idx, nodes, edges;
  vector< pair< int, pii > > edge_list;
  vector< pair< pii, pii > > q_list;
  struct disjoint_set dset[MAX];

  void init(int n, vector<vector<int>>& el, vector<vector<int>>& ql) {
    idx = 0;

    edges = el.size();
    nodes = n;

    edge_list.clear();
    for(int i=0; i<edges; i+=1) {
      edge_list.push_back(make_pair(el[i][2], pii(el[i][0], el[i][1])));
      //nodes = max(nodes, el[i][0]);
      //nodes = max(nodes, el[i][1]);
    }

    //sort edges by increasing order
    sort(edge_list.begin(), edge_list.end());

    // increment number of nodes bu 1 for easier loop-ending condition
    //nodes += 1;

    for(int i=0; i<nodes; i+=1) {
      dset[i].parent = i;
      dset[i].rank = 0;
    }

    qsz = ql.size();
    q_list.clear();
    for(int i=0; i<qsz; i+=1) {
      q_list.push_back(make_pair(pii(ql[i][2], i), pii(ql[i][0], ql[i][1])));
    }

    //sort queries by increasing order of edge length limit
    sort(q_list.begin(), q_list.end());
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

  void peocess(int limit) {
    int u, v, pu, pv;

    while(idx < edges) {
      if(edge_list[idx].ff >= limit) break;

      u = edge_list[idx].ss.ff;
      v = edge_list[idx].ss.ss;

      pu = find_set(u);
      pv = find_set(v);

      /*u and v are not in same set, connect them by this edge and add a link among them*/
      if(pu != pv) {
        union_by_rank(pu, pv);
      }

      idx += 1;
    }
  }
};