//
// Created by Islam, Abdullah Al Raqibul on 09/02/22.
//

class Graph {
private:
  int n;
  vector<vector<int>> g;
  vector<int> in_deg;

public:
  vector<int> topo_order;

  Graph(int n_, vector<vector<int>>& cond) {
    n = n_;
    g.resize(n_);
    in_deg.resize(n_, 0);
    build(cond);
  }

  void add_edge(int u, int v) {
    g[u].push_back(v);
    in_deg[v] += 1;
  }

  void build(vector<vector<int>>& cond) {
    for(auto c : cond) {
      add_edge(c[0] - 1, c[1] - 1);
    }
  }

  vector<int> generate_topo() {
    queue<int> q;
    int u;

    for(int i=0; i<n; i+=1) if(!in_deg[i]) q.push(i);

    while(!q.empty()) {
      u = q.front(); q.pop();
      topo_order.push_back(u);

      for(int v : g[u]) {
        in_deg[v] -= 1;
        if(!in_deg[v]) q.push(v);
      }
    }
    return topo_order;
  }
};

class Solution {
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<vector<int>> ret(k, vector<int>(k, 0));

    Graph rowG(k, rowConditions);
    Graph colG(k, colConditions);

    rowG.generate_topo();
    colG.generate_topo();

    if(rowG.topo_order.size() != k || colG.topo_order.size() != k) return vector<vector<int>>{};

    map<int, int> rmap;
    for(int i=0; i<k; i+=1) rmap[rowG.topo_order[i]] = i;
    for(int j=0; j<k; j+=1) ret[rmap[colG.topo_order[j]]][j] = colG.topo_order[j] + 1;

    return ret;
  }
};