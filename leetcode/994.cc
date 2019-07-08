class Solution {
public:
	bool rot(vector<vector<int>>& grid, int m) {
	  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
	  bool flag = false;
		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[i].size(); ++j) {
			  if(grid[i][j] == m-1) {
			    for(int k = 0; k < 4; ++k) {
			      if(i+dir[k][0] >=0 && i+dir[k][0] < grid.size()
			         && j+dir[k][1] >=0 && j+dir[k][1] < grid[i].size()
			         && grid[i+dir[k][0]][j+dir[k][1]] == 1) {
			        grid[i+dir[k][0]][j+dir[k][1]] = m;
			        flag = true;
            }
          }
			  }
      }
    return flag;
	}

	int orangesRotting(vector<vector<int>>& grid) {
	  int x = 2;
	  while(rot(grid, ++x));
		for(int i = 0; i < grid.size(); ++i)
			for(int j = 0; j < grid[i].size(); ++j) 
			  if(grid[i][j] == 1) return -1;
		return x-3;
	}
};
