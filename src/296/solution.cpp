//
// Created by Islam, Abdullah Al Raqibul on 11/13/22.
//

class Solution {
public:
  int minTotalDistance(vector<vector<int>>& grid) {
    vector<int> xpos, ypos;

    for(int i=0; i<grid.size(); i+=1) {
      for(int j=0; j<grid[i].size(); j+=1) {
        if(grid[i][j]) {
          xpos.push_back(i);
          ypos.push_back(j);
        }
      }
    }

    sort(ypos.begin(), ypos.end());

    int x = xpos[xpos.size() / 2];
    int y = ypos[ypos.size() / 2];
    int ret = 0;

    for(int i=0; i<grid.size(); i+=1) {
      for(int j=0; j<grid[i].size(); j+=1) {
        if(grid[i][j]) {
          ret += (abs(i - x) + abs(j - y));
        }
      }
    }

    return ret;
  }
};