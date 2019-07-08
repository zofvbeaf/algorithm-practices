class Solution {
public:

  void dfs(vector<vector<int>>& grid, int x, int y, int cnt) {
    grid[x][y] = -1; 
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 
    for(int i = 0; i < 4; ++i) {
      int a = x+dir[i][0], b = y+dir[i][1];
      if(a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size()) {
        if(grid[a][b] == 0) dfs(grid, a, b, cnt+1);
        else if(grid[a][b] == 2) {
          ans += (cnt == num);
        } 
      }
    }
    grid[x][y] = 0;
  }

  int uniquePathsIII(vector<vector<int>>& grid) {
    vector<int> path;
    queue<pair<int, int>> q;
    int sx, sy;
    num = ans = 0;
    int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}}; 
    for(int i = 0; i < grid.size(); ++i) {
      for(int j = 0; j < grid[i].size(); ++j) {
        if(grid[i][j] == 1) {
          sx = i, sy = j;
          ++num;
        }
        else if(grid[i][j] == 0) ++num;
      }
    } 
    dfs(grid, sx, sy, 1);
    return ans;
  }
  int num, ans;
};
