//
// Created by Islam, Abdullah Al Raqibul on 01/27/22.
//

#define pii pair< int, int >
#define ff first
#define ss second

struct comp {
  bool operator() (const pii &a, const pii &b) {
    return a.ss > b.ss;
  }
};

class Solution {
public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    int u, v, w, sz;
    vector<int> dist(n, maxMoves+1);
    vector<bool> vis(n, false);
    priority_queue< pii, vector< pii >, comp > pq;
    vector<pii> graph[n];
    map<pii, int> used;
    int ret = 0;

    for(vector<int> e:edges) {
      u = e[0];
      v = e[1];
      w = e[2];

      graph[u].push_back(pii(v, w));
      graph[v].push_back(pii(u, w));
    }

    dist[0] = 0;
    pq.push(pii(0, 0));

    while(!pq.empty()) {
      u = pq.top().ff;
      pq.pop();
      if(vis[u]) continue;
      ret += 1;

      sz = graph[u].size();
      for(int i=0; i<sz; i+=1) {
        v = graph[u][i].ff;
        w = graph[u][i].ss;
        used[{u, v}] = min(w, maxMoves - dist[u]);

        if(!vis[v] && dist[v] > (dist[u] + w + 1)) {
          dist[v] = dist[u] + w + 1;
          pq.push(pii(v, dist[v]));
        }
      }
      vis[u] = true;
    }

    for(vector<int> e:edges) {
      u = e[0];
      v = e[1];
      w = e[2];

      ret += min(w, used[{u, v}] + used[{v, u}]);
    }

    return ret;
  }
};