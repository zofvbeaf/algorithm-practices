class Solution {
public:
  int maximumGap(vector<int>& nums) {
    if(nums.size() < 2) return 0;
    int min_num = nums[0], max_num = nums[0];
    for(int i = 1; i < nums.size(); ++i) {
      min_num = min(min_num, nums[i]);
      max_num = max(max_num, nums[i]);
    }
    int gap = (int)ceil((double)(max_num - min_num)/(nums.size()-1));
    vector<int> min_bucket(nums.size()-1, INT_MAX);
    vector<int> max_bucket(nums.size()-1, INT_MIN);
    for(int i = 0; i < nums.size(); ++i) {
      if(nums[i] == min_num || nums[i] == max_num) continue;
      int idx = (nums[i] - min_num)/gap;
      min_bucket[idx] = min(nums[i], min_bucket[idx]);
      max_bucket[idx] = max(nums[i], max_bucket[idx]);
    }
  
    int max_gap = INT_MIN;
    int previous = min_num;
    for(int i = 0; i < nums.size()-1; ++i) {
      if(min_bucket[i] == INT_MAX && max_bucket[i] == INT_MIN) continue;
      max_gap = max(max_gap, min_bucket[i] - previous);
      previous = max_bucket[i]; 
    } 
    return max(max_gap, max_num - previous); 
  }
};
