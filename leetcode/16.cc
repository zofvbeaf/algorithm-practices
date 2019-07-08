class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end()); 
		int res = nums[0] + nums[1] + nums[2];
		int ans = abs(target - res);
		for(auto i = nums.begin(); i != nums.end(); ++i) {
			for(auto j = i+1; j != nums.end(); ++j) {
				if(j+1 == nums.end()) break; 
				int x = target-*i-*j;
				auto pos = lower_bound(j+1, nums.end(), x);
				if(pos == nums.end()) {
					if(ans > abs(x-nums.back())) {
						ans = x-nums.back();
						res = *i+*j+nums.back(); 
					}
				}
				else if(pos == j+1) { 
					if(ans > abs(x-*pos)) {
						ans = abs(x-*pos);
						res = *i + *j + *pos;
					}
				}
				else {
					ans = min(ans, min(abs(x-*pos), abs(x-*(pos-1))));
					res = ans == abs(x-*pos) ? (*i+*j+*pos) : ((ans == abs(x-*(pos-1))) ? (*i+*j+*(pos-1)) : res);
				}
			}
		}
		return res;
	}
};
