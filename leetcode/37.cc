class Solution {
public:
  void check(vector<vector<char>>& board, int x, int y, char c) {
    static int f[3][3] = {{10, 13, 16}, {37, 40, 43}, {64, 67, 70}};
    static int dir[9] = {0, -1, 1, -9, 9, -10, 10, -8, 8};
    for(int i = 0; i < 9; ++i) 
      if(board[x][i] == c || board[i][y] == c) return false;
    int m = f[x/3][y/3];
    for(int i = 0; i < 9; ++i) 
      if(board[(m + dir[i])/9][(m + dir[i])%9] == c) return false;
    return true;
  }
  void search(vector<vector<char>>& board, int x) {
    if(x == 81) { flag = true; return; }
    for(int i = 0; i < 9; ++i) 
      for(int j = 0; j < 9; ++j) {
        if(flag) return;
        if(board[i][j] == '.') {
          for(char c = '0'; c <= '9'; ++c) {
            if(check(board, i, j, c)) {
              board[i][j] = c;
              search(board, x+1);
              if(flag) return;
              board[i][j] = '.';
            }
          }
        }
      }
  }

  void solveSudoku(vector<vector<char>>& board) {
    int x = 0;
    flag = false;
    for(int i = 0; i < 9; ++i) 
      for(int j = 0; j < 9; ++j) {
        x += (board[i][j] != '.');
      }
    search(board, x);
  }
  bool flag;
};
