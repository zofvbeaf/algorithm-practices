class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> ans;
    map<int, vector<pair<int, int>>> res;
    for(auto i = nums.begin(); i != nums.end(); ++i) {
      for(auto j = i+1; j != nums.end(); ++j) {
        res[*i+*j].push_back(make_pair(i-nums.begin(), j-nums.begin()));
      }
    }
    for(auto i : res) {
      if(target >= i.first + i.first) {
        for(auto j : i.second) {
          for(auto k : res[target - i.first]) {
            if(j.first != k.first && j.second != k.second
                && j.first != k.second && j.second != k.first) 
              ans.push_back({j.first, j.second, k.first, k.second});
          }
        }
      }
      else if(target < i.first + i.first) break;
    }
    return ans;
  }
};
