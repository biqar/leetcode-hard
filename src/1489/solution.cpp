//
// Created by Islam, Abdullah Al Raqibul on 02/04/22.
//

class Solution {
public:
#define pii pair< int, int >
#define ff first
#define ss second

  static const int MAX = 205;

  struct disjoint_set {
    int parent, rank;
  };

  int n, e;
  struct disjoint_set dset[MAX];

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

  int calculate_mst(vector< pair< int, pii > > loc_edge_list) {
    int u, v, pu, pv, total_mst_cost = 0;;

    //initialize disjoint set data-structure
    init_dsd();

    //sort edges by increasing order
    sort(loc_edge_list.begin(), loc_edge_list.end());

    for(int i=0; i<e; i+=1) {
      u = loc_edge_list[i].ss.ff;
      v = loc_edge_list[i].ss.ss;

      pu = find_set(u);
      pv = find_set(v);

      /*u and v are not in same set, connect them by this edge and add a link among them*/
      if(pu != pv) {
        total_mst_cost += loc_edge_list[i].ff;
        union_by_rank(pu, pv);
      }
    }

    return total_mst_cost;
  }

  void build_graph(int nodes, vector<vector<int>>& edges, vector< pair< int, pii > >& edge_list) {
    n = nodes;
    e = edges.size();

    edge_list.clear();

    for(int i=0; i<e; i+=1) {
      edge_list.push_back(make_pair(edges[i][2], pii(edges[i][0], edges[i][1])));
    }
  }

  vector<vector<int>> findCriticalAndPseudoCriticalEdges(int nodes, vector<vector<int>>& edges) {
    vector< pair< int, pii > > edge_list;
    vector<int> cri, sudo;
    vector<vector<int>> ret;

    //build graph
    build_graph(nodes, edges, edge_list);

    //apply kruskal algorithm on the input graph to calculate mst
    int ref_mst_cost = calculate_mst(edge_list);

    for(int i=0; i<e; i+=1) {
      edge_list[i].ff += 1;

      if(ref_mst_cost < calculate_mst(edge_list)) {
        cri.push_back(i);
        edge_list[i].ff -= 1;
      }
      else {
        edge_list[i].ff -= 2;
        if(ref_mst_cost > calculate_mst(edge_list)) {
          sudo.push_back(i);
        }
        edge_list[i].ff += 1;
      }
    }

    ret.push_back(cri);
    ret.push_back(sudo);
    return ret;
  }
};