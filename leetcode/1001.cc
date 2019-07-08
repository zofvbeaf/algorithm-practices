class Solution {
public:
  vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    vector<int> ans;
    for(int i = 0; i < queries.size(); ++i) {
      int x = queries[i][0], y = queries[i][1], z = 0;
      for(int j = 0; j < lamps.size(); ++j) {
        if(lamps[j][0] < 0) continue;
        if(!z && x == lamps[j][0] || y == lamps[j][1] 
            || abs(x-lamps[j][0]) == abs(y-lamps[j][1])) {
          z = 1;
        }
        if((abs(lamps[j][0]-x) == 1 && abs(lamps[j][1]-y) <= 1)
            || (abs(lamps[j][0]-x) <= 1 && abs(lamps[j][1]-y) == 1))
          lamps[j][0] = lamps[j][1] = -1;
      }
      ans.push_back(z);
    }
    return ans;
  }
};
