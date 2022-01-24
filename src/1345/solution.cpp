//
// Created by Islam, Abdullah Al Raqibul on 01/23/22.
//

class Solution {
public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();
    vector<int> g[n];
    map<int, vector<int>> m;

    for(int i=0; i<n; i+=1) m[arr[i]].push_back(i);

    for(int i=0; i<n; i+=1) {
      if(i) g[i].push_back(i-1);
      if(i!=n-1) g[i].push_back(i+1);
    }

    // for(auto const& [key, val] : m) {
    //     int sz = val.size();
    //     for(int i=0; i<sz; i+=1) {
    //         for(int j=i+1; j<sz; j+=1) {
    //             g[val[i]].push_back(val[j]);
    //             g[val[j]].push_back(val[i]);
    //         }
    //     }
    // }

    // cout << m[arr[0]].size() << endl;

    queue<int> q;
    int u;
    // set<int> flg;
    vector<int> dist(n, n*2);
    q.push(0);
    dist[0] = 0;
    // flg.insert(arr[0]);
    while(!q.empty()) {
      // cout << u << endl;
      u = q.front();
      q.pop();
      if(u == n-1) return dist[u];

      for(int v : g[u]) {
        if(dist[v] > dist[u] + 1) {
          // if(flg.find(arr[v]) == flg.end()) {
          q.push(v);
          dist[v] = dist[u] + 1;
          // flg.insert(arr[v]);
        }
      }

      const vector<int>& tmp = m[arr[u]];
      for(int v : tmp) {
        if(dist[v] > dist[u] + 1) {
          // if(flg.find(arr[v]) == flg.end()) {
          q.push(v);
          dist[v] = dist[u] + 1;
          // flg.insert(arr[v]);
        }
      }
      m[arr[u]].clear();
    }

    // return arr[n-1];
    return -1;
  }
};