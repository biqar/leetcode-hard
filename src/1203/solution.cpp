//
// Created by Islam, Abdullah Al Raqibul on 02/03/22.
//

class Solution {
public:
  vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    for(int i=0; i<n; i+=1) {
      if(group[i] == -1) {
        group[i] = m;
        m += 1;
      }
    }

    vector<vector<int>> irGraph(n), grGraph(m), giGraph(m);
    vector<int> iDeg(n, 0), gDeg(m, 0);

    for(int i=0; i<n; i+=1) {
      giGraph[group[i]].push_back(i);
    }

    int u, v, gu, gv, sz;
    for(u=0; u<n; u+=1) {
      gu = group[u];
      sz = beforeItems[u].size();

      for(int i=0; i<sz; i+=1) {
        v = beforeItems[u][i];
        gv = group[v];

        if(gu == gv) {
          irGraph[v].push_back(u);
          iDeg[u] += 1;
        }
        else {
          grGraph[gv].push_back(gu);
          gDeg[gu] += 1;
        }
      }
    }

    vector<int> ret, gRound;
    queue<int> gq;
    for(int i=0; i<m; i+=1) {
      if(!gDeg[i]) gq.push(i);
    }

    while(!gq.empty()) {
      gu = gq.front(); gq.pop();

      gRound.clear();
      topoInGroup(gu, giGraph[gu], iDeg, irGraph, gRound);
      if(gRound.size() != giGraph[gu].size()) return vector<int>();
      ret.insert(ret.end(), gRound.begin(), gRound.end());

      sz = grGraph[gu].size();
      for(int i=0; i<sz; i+=1) {
        gv = grGraph[gu][i];

        gDeg[gv] -= 1;
        if(!gDeg[gv]) gq.push(gv);
      }
    }

    return ret.size() == n ? ret : vector<int>();
  }

  void topoInGroup(int gu, vector<int> &gMembers, vector<int> &iDeg, vector<vector<int>> &irGraph, vector<int> &ret) {
    int sz = gMembers.size();
    int u, v;
    queue<int> q;

    for(int i=0; i<sz; i+=1) {
      u = gMembers[i];
      if(!iDeg[u]) q.push(u);
    }

    while(!q.empty()) {
      u = q.front();
      q.pop();

      ret.push_back(u);

      sz = irGraph[u].size();

      for(int i=0; i<sz; i+=1) {
        v = irGraph[u][i];

        iDeg[v] -= 1;
        if(!iDeg[v]) q.push(v);
      }
    }
  }
};