//
// Created by Islam, Abdullah Al Raqibul on 02/03/22.
//

class Solution {
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));

    queue<vector<int>> q;
    q.push(vector<int>{0, 0, grid[0][0]});
    dist[0][0] = grid[0][0];
    int step = 0, sz;
    while(!q.empty()) {
      sz = q.size();

      for(int j=0; j<sz; j+=1) {
        vector<int> u = q.front();
        q.pop();

        if(u[2] > k) continue;
        if(u[0] == r-1 && u[1] == c-1) return step;

        for(int i=0; i<4; i+=1) {
          int vx = u[0] + dir[i][0];
          int vy = u[1] + dir[i][1];

          if(vx<0 || vx>=r) continue;
          if(vy<0 || vy>=c) continue;

          int vd = u[2] + grid[vx][vy];
          if(vd > k) continue;

          if(dist[vx][vy] > vd) {
            dist[vx][vy] = vd;
            q.push(vector<int>{vx, vy, vd});
          }
        }
      }
      step += 1;
    }
    return dist[r-1][c-1] > k ? -1 : step;
  }
};