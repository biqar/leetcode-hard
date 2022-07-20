//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  void update_dist(int st, vector<vector<int>>& g, vector<int>& dist) {
    int sz = g[st].size();
    for(int i=0; i<sz; i+=1) {
      int nx = g[st][i];
      if(dist[nx] == 0) {
        dist[nx] = dist[st] + 1;
        update_dist(nx, g, dist);
      }
    }
  }

  int checkValidity(int n, vector<vector<int>>& edges, int mask) {
    vector<int> can(n+1, 0);
    vector<vector<int>> g(n+1);
    int ret = -1, st = -1;

    //cout << "in round " << mask << endl;
    for(int i=0; i<n-1; i+=1) {
      if(mask & (1<<i)) {
        int u = edges[i][0];
        int v = edges[i][1];

        //cout << u << " " << v << endl;
        can[u] = can[v] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
        if(st == -1) st = u;
      }
    }

    for(int i=1; i<=n; i+=1) {
      if(can[i]) {
        //cout << "st: " << i << endl;
        vector<int> dist(n+1, 0);
        dist[i] = 1;
        update_dist(i, g, dist);

        for(int j=1; j<=n; j+=1) {
          if(can[j] && !dist[j]) return -1;
          if(!can[j] && dist[j]) return -1;
          ret = max(ret, dist[j]);
        }

        //cout << "distance: " << (ret - 2) << endl;
      }
    }

    return ret - 2;
  }

  vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    int com = (1 << (n-1));
    vector<int> cnt(n-1, 0);
    for(int i=1; i<com; i+=1) {
      // check valid subtree
      // get max distance
      int d = checkValidity(n, edges, i);
      if(d >= 0) cnt[d] += 1;
    }

    return cnt;
  }
};