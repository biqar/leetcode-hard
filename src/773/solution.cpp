//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
public:
  string get_state(vector<vector<int>>& board) {
    string ret = "";
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        ret += board[i][j];
      }
    }
    return ret;
  }

  int slidingPuzzle(vector<vector<int>>& board) {
    int res = 0;
    set<string> visited;
    queue<pair<vector<vector<int>>, vector<int>>> q;

    vector<vector<int>> correct{{1, 2, 3}, {4, 5, 0}};
    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (board[i][j] == 0) q.push({board, {i, j}});
      }
    }
    while (!q.empty()) {
      for (int i = q.size() - 1; i >= 0; --i) {
        vector<vector<int>> t = q.front().first;
        auto zero = q.front().second;
        q.pop();

        if (t == correct) return res;
        visited.insert(get_state(t));
        for (auto dir : dirs)
        {
          int x = zero[0] + dir[0], y = zero[1] + dir[1];
          if (x < 0 || x >= 2 || y < 0 || y >= 3) continue;

          swap(t[zero[0]][zero[1]], t[x][y]);
          if (!visited.count(get_state(t))) q.push({t, {x, y}});
          swap(t[zero[0]][zero[1]], t[x][y]);
        }
      }
      ++res;
    }
    return -1;
  }
};