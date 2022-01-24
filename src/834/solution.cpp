//
// Created by Islam, Abdullah Al Raqibul on 01/24/22.
//

class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int> ret = vector<int>(n, 0);
    vector<int> cnt = vector<int>(n, 1);
    vector<vector<int>> graph = vector<vector<int>>(n);

    for(vector<int> e: edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    dfs_build_parent(0, -1, graph, ret, cnt);
    dfs_build_child(0, -1, graph, ret, cnt, n);

    return ret;
  }

  void dfs_build_parent(int u, int pr,
                        vector<vector<int>>& graph,
                        vector<int>& ret, vector<int>& cnt) {
    for(int v: graph[u]) {
      if(v != pr) {
        dfs_build_parent(v, u, graph, ret, cnt);
        ret[u] += (ret[v] + cnt[v]);
        cnt[u] += cnt[v];
      }
    }
  }

  void dfs_build_child(int u, int pr,
                       vector<vector<int>>& graph,
                       vector<int>& ret, vector<int>& cnt, int n) {
    for(int v: graph[u]) {
      if(v != pr) {
        ret[v] = (ret[u] - cnt[v] + n - cnt[v]);
        dfs_build_child(v, u, graph, ret, cnt, n);
      }
    }
  }
};