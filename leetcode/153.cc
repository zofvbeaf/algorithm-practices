class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0, r = nums.size()-1;
    while(l < r) {
      if(nums[l] < nums[r]) return nums[l];
      int m = ((l+r)>>1);
      if(nums[m] < nums[l]) r = m;
      else l = m+1;
    }
    return nums[l];
	}
};
