class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    vector<int> height(m, 0);
    vector<int> left(m, 0);
    vector<int> right(m, m);
    for(int i = 0; i < n; ++i) {
      int cur_left = 0, cur_right = m;
      for(int j = 0; j < m; ++j) {
        if(matrix[i][j] == '1') ++height[j]; 
        else height[j] = 0;
      }
      for(int j = 0; j < m; ++j) {
        if(matrix[i][j] == '1') left[j] = max(left[j], cur_left); 
        else left[j] = 0, cur_left = j+1;
      }
      for(int j = m-1; j >= 0; --j) {
        if(matrix[i][j] == '1') right[j] = min(right[j], cur_right); 
        else right[j] = m, cur_right = j;
      }
      for(int j = 0; j < m; ++j) 
        ans = max(ans, (right[j]-left[j])*height[j]);
    }
    return ans; 
  }
};
