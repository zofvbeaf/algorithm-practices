class Solution {
public:
  bool Find(int target, vector<vector<int> > array) {
    if(array.empty() || array[0].empty() || array[0][0] > target) 
      return false;
    int n = array.size(), m = array[0].size();
    int i = 0, j = m-1;
    while(i < n && j >= 0) {
      if(array[i][j] == target) 
        return true;
      else if(array[i][j] < target) 
        ++i;
      else 
        --j;
    }
    return false; 
  }
};
