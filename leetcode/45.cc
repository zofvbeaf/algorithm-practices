class Solution {
public:
  int jump(vector<int>& nums) {
    if(nums.size() < 2) return 0;
    vector<int> temp;
    for(int i = nums.size()-2; i >= 0; --i) {
      if(i+nums[i]+1 >= nums.size()) temp.push_back(1);
      else if(!temp.empty()) {
        int x = 1<<30;
        for(int j = nums[i]; j > 0; --j)
          if(temp[temp.size()-j] >= 0) x = min(x, temp[temp.size()-j]);
        if(x != 1<<30) temp.push_back(x+1);
        else temp.push_back(-1);
      }
      else temp.push_back(-1);
    }
    return temp.back();
  }
};

