class Solution {
public:
  int numRookCaptures(vector<vector<char>>& board) {
    int x, y;
    int ans = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for(int i = 0; i < board.size(); ++i) {
      for(int j = 0; j < board.size(); ++j) {
        if(board[i][j] == 'R') {
          x = i, y = j;
          break;
        }
      }
    }
    for(int i = 0; i < 4; ++i) {
      int a = x + dir[i][0], b = y + dir[i][1];
      while(a >= 0 && a < board.size() 
            && b >= 0 && b < board.size()) {
        if(board[a][b] == '.') {
          a += dir[i][0];
          b += dir[i][1];
          continue;
        }
        else if(board[a][b] == 'p') ++ans;
        break;
      }
    } 
    return ans;
  }
};
