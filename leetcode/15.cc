class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> ans;
    map<int, set<int>> res;
    for(auto i = nums.begin(); i != nums.end(); ++i) {
      for(auto j = i+1; j != nums.end(); ++j) {
        if(binary_search(j+1, nums.end(), 0-(*i+*j))) res[*i].insert(*j);
      }
    }
    for(auto i : res) 
      for(auto j : i.second)
      ans.push_back({i.first, j, 0-i.first-j});
    return ans;
  }
};

