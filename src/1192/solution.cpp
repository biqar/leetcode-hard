//
// Created by Islam, Abdullah Al Raqibul on 02/03/22.
//

#define MAX 100005

class Solution {
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector< vector<int> > Bridges;
    for(int i=0; i<n; i+=1) G[i].clear();
    int sz = connections.size();
    for(int i=0; i<sz; i+=1) {
      G[connections[i][0]].push_back(connections[i][1]);
      G[connections[i][1]].push_back(connections[i][0]);
    }
    memset(used, 0, sizeof(used));

    dfs(0, -1, Bridges);
    return Bridges;
  }

private:
  vector<int> G[MAX];
  int low[MAX], vis[MAX], used[MAX], dfstime;

  void dfs(int u, int par, vector< vector<int> >& Bridges) {
    //cout << u << " " << par << endl;
    int i, v;
    used[u] = 1;
    vis[u] = low[u] = ++dfstime;
    for(i = 0; i < G[u].size(); i++) {
      v = G[u][i];
      //cout << "\t" << v << endl;
      if(v == par) continue;
      if(used[v]) low[u] = min(low[u], vis[v]);
      else {
        dfs(v, u, Bridges);
        low[u] = min(low[u], low[v]);
        if(low[v] > vis[u]) Bridges.push_back(vector<int>{u, v});
      }
    }
  }
};