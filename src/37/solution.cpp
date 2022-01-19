//
// Created by Islam, Abdullah Al Raqibul on 11/19/21.
//

class Solution {
private:
  vector<pair<int, int>> empty;
  int num_empty;

  bool is_valid_in_row(int r, int val, vector<vector<char>>& board) {
    for(int j=0; j<9; j+=1) {
      if(board[r][j] != '.') {
        if((board[r][j] - '0') == val) return false;
      }
    }
    return true;
  }

  bool is_valid_in_column(int c, int val, vector<vector<char>>& board) {
    for(int i=0; i<9; i+=1) {
      if(board[i][c] != '.') {
        if((board[i][c] - '0') == val) return false;
      }
    }
    return true;
  }

  bool is_valid_in_subboard(int r, int c, int val, vector<vector<char>>& board) {
    int st_r, st_c, nd_r, nd_c;
    if(r>=0 && r<=2) {  // 1st row
      st_r = 0; nd_r = 2;
      if(c>=0 && c<=2) {  // 1st column
        st_c = 0; nd_c = 2;
      }
      else if(c>=3 && c<=5) { // 2nd column
        st_c = 3; nd_c = 5;
      }
      else {  // 3rd column
        st_c = 6; nd_c = 8;
      }
    }
    else if(r>=3 && r<=5) { // 2nd row
      st_r = 3; nd_r = 5;
      if(c>=0 && c<=2) {  // 1st column
        st_c = 0; nd_c = 2;
      }
      else if(c>=3 && c<=5) { // 2nd column
        st_c = 3; nd_c = 5;
      }
      else {  // 3rd column
        st_c = 6; nd_c = 8;
      }
    }
    else {  // 3rd row
      st_r = 6; nd_r = 8;
      if(c>=0 && c<=2) {  // 1st column
        st_c = 0; nd_c = 2;
      }
      else if(c>=3 && c<=5) { // 2nd column
        st_c = 3; nd_c = 5;
      }
      else {  // 3rd column
        st_c = 6; nd_c = 8;
      }
    }

    for(int i=st_r; i<=nd_r; i+=1) {
      for(int j=st_c; j<=nd_c; j+=1) {
        if(board[i][j] != '.') {
          if((board[i][j] - '0') == val) return false;
        }
      }
    }
    return true;
  }

  bool backtrack(int pos, vector<vector<char>>& board) {
    if(pos == num_empty) return true;

    int r = empty[pos].first, c = empty[pos].second;
    for(int val=1; val<10; val+=1) {
      if(is_valid_in_row(r, val, board)
         && is_valid_in_column(c, val, board)
         && is_valid_in_subboard(r, c, val, board)) {
        board[r][c] = (val + '0');
        if(backtrack(pos+1, board)) return true;
        board[r][c] = '.';
      }
    }
    return false;
  }

public:
  void solveSudoku(vector<vector<char>>& board) {
    empty.clear();
    num_empty = 0;

    for(int i=0; i<9; i+=1) {
      for(int j=0; j<9; j+=1) {
        if(board[i][j] == '.') {
          num_empty += 1;
          empty.push_back(make_pair(i, j));
        }
      }
    }

    backtrack(0, board);
  }
};