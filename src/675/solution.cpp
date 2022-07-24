//
// Created by Islam, Abdullah Al Raqibul on 07/23/22.
//

#define INF 100000000


class Solution {
public:
  int bfs(int lookup, vector<vector<int>>& forest, vector<vector<int>>& dist) {
    if(forest[x][y] == lookup) return 0;
    queue<pair<int, int>> q;
    fill(dist.begin(), dist.end(), vector<int>(c, INF));
    q.push(make_pair(x, y));
    dist[x][y] = 0;

    int ux, uy, vx, vy;
    while(!q.empty()) {
      ux = q.front().first;
      uy = q.front().second;
      q.pop();

      for(int i=0; i<4; i+=1) {
        vx = ux + dr[i];
        vy = uy + dc[i];

        if(vx < 0 || vx >= r || vy < 0 || vy >= c) continue;

        if(forest[vx][vy] == 0) continue;

        if(dist[vx][vy] > dist[ux][uy] + 1) {
          dist[vx][vy] = dist[ux][uy] + 1;
          q.push({vx, vy});
        }

        if(forest[vx][vy] == lookup) {
          x = vx;
          y = vy;
          return dist[vx][vy];
        }
      }
    }
    return -1;
  }

  int cutOffTree(vector<vector<int>>& forest) {
    r = forest.size();
    c = forest[0].size();

    vector<vector<int>> dist(r, vector<int>(c));

    order.clear();
    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        if(forest[i][j] > 1) order.push_back(forest[i][j]);
      }
    }

    sort(order.begin(), order.end());

    x = 0;
    y = 0;
    int d, ret = 0;
    for(int i : order) {
      d = bfs(i, forest, dist);
      if(d == -1) return -1;
      ret += d;
    }

    return ret;
  }

private:
  int r, c;
  vector<int> order;
  int x, y;

  // Direction vectors
  int dr[4] = { -1, 0, 1, 0 };
  int dc[4] = { 0, 1, 0, -1 };
};