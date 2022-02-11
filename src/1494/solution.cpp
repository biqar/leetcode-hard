//
// Created by Islam, Abdullah Al Raqibul on 02/10/22.
//

class Solution {
public:
  int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
    int in[n+2], out[n+2];
    vector<int> g[n+2];
    int sz = dependencies.size();

    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));

    for(int i=0; i<sz; i+=1) {
      in[dependencies[i][1]] += 1;
      out[dependencies[i][0]] += 1;
      g[dependencies[i][0]].push_back(dependencies[i][1]);
    }

    priority_queue <pair<int, int> > q;
    for(int i=1; i<=n; i+=1) {
      if(in[i] == 0) q.push(make_pair(out[i], i));
    }

    int ret = 0;
    while(!q.empty()) {
      int cur_sz = q.size();
      cur_sz = min(k, cur_sz);

      priority_queue <pair<int, int> > qi;
      for(int i=0; i<cur_sz; i+=1) {
        int curr = q.top().second; q.pop();
        for(int j=0; j<g[curr].size(); j+=1) {
          int neigh = g[curr][j];
          in[neigh] -= 1;
          if(in[neigh] == 0) {
            qi.push(make_pair(out[neigh], neigh));
          }
        }
      }
      while(!qi.empty()) {
        q.push(qi.top());
        qi.pop();
      }
      ret += 1;
    }

    return ret;
  }
};