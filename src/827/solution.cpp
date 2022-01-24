//
// Created by Islam, Abdullah Al Raqibul on 01/24/22.
//

class Solution {
public:
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, -1, 0, 1};

  int largestIsland(vector<vector<int>>& grid) {
    int r, c, idx = 2, ret = 0;
    r = grid.size();
    c = grid[0].size();
    unordered_map<int, int> area;

    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        if(grid[i][j] == 1) {
          area[idx] = dfs(grid, r, c, i, j, idx);
          ret = max(ret, area[idx]);
          idx += 1;
        }
      }
    }

    // for(int i=0; i<r; i+=1) {
    //     for(int j=0; j<c; j+=1) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << area[2] << " " << area[3] << " " << area[4] << endl << endl;

    for(int i=0; i<r; i+=1) {
      for(int j=0; j<c; j+=1) {
        if(grid[i][j] == 0) {
          unordered_set<int> islands;

          //cout << i << " " << j << ":" << endl;
          for(auto neigh : get_neighbors(r, c, i, j)) {
            if(grid[neigh.first][neigh.second] != 0) {
              //cout << neigh.first << " " << neigh.second << endl;
              islands.insert(grid[neigh.first][neigh.second]);
            }
          }

          int curr = 1;
          for(auto iid : islands) curr += area[iid];
          ret = max(curr, ret);

          //cout << curr << endl;
        }
      }
    }

    return ret;
  }

  int dfs(vector<vector<int>>& grid, int r, int c, int i, int j, int idx) {
    int ret = 1;
    grid[i][j] = idx;

    for(auto neigh : get_neighbors(r, c, i, j)) {
      if(grid[neigh.first][neigh.second] == 1) {
        ret += dfs(grid, r, c, neigh.first, neigh.second, idx);
      }
    }
    return ret;
  }

  vector<pair<int, int>> get_neighbors(int r, int c, int i, int j) {
    vector<pair<int, int>> ret;
    for(int move=0; move<4; move+=1) {
      int ri = dr[move];
      int ci = dc[move];
      if(i+ri < 0 || i+ri>=r) continue;
      if(j+ci < 0 || j+ci>=c) continue;
      ret.push_back(make_pair(i+ri, j+ci));
    }

    return ret;
  }
};