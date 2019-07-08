class Solution {
public:
  void search(int& n, vector<string>& temp, int x, int& ans, vector<vector<int>>& flag) {
    if(x == n) {
      ++ans;
      return;
    }
    for(int y = 0; y < n; ++y) {
      if(!flag[0][x+y] && !flag[1][x-y+n-1] && !flag[2][y]) {
        temp[x][y] = 'Q';
        flag[0][x+y] = flag[1][x-y+n-1] = flag[2][y]= 1;
        search(n, temp, x+1, ans, flag);
        temp[x][y] = '.';
        flag[0][x+y] = flag[1][x-y+n-1] = flag[2][y] = 0;
      }
    }
  }

  int totalNQueens(int n) {
    int ans = 0;
    vector<vector<int>> flag(3, vector<int>(n*2, 0));
    vector<string> temp(n ,string(n, '.'));
    search(n, temp, 0, ans, flag);
    return ans;
  }
};


