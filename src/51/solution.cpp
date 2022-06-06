//
// Created by Islam, Abdullah Al Raqibul on 06/05/22.
//

class Solution {
public:
  bool is_valid(vector<string>& b, int n, int r, int c) {
    for(int i=0; i<n; i+=1) {
      if(b[i][c] == 'Q') return false;
      if(r - i >= 0 && c - i >= 0 && b[r - i][c - i] == 'Q') return false;
      if(r - i >= 0 && c + i < n && b[r - i][c + i] == 'Q') return false;
    }
    return true;
  }

  void bt_traverse(vector<string>& b, int r, int n) {
    if(r == n) {
      ret.push_back(b);
      return;
    }

    for(int c=0; c<n; c+=1) {
      if(is_valid(b, n, r, c)) {
        b[r][c] = 'Q';
        bt_traverse(b, r + 1, n);
        b[r][c] = '.';
      }
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    bt_traverse(board, 0, n);
    return ret;
  }

private:
  vector<vector<string> > ret;
};