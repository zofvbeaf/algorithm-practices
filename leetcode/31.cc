class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int x = -1;
		for(int i = nums.size()-1; i > 0; --i) {
			if(nums[i] > nums[i-1]) {
				x = i-1;
				break;
			}
		}
		if(x == -1) { // 321 -》 123
			int i = 0, j = nums.size()-1;
			while(i < j) {
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				++i, --j;
			}
		}
		else { // 从后往前找第一个比 nums[x] 大的数，交换，并翻转原来 x 之后的数
			int y = nums.size()-1;
			while(y > x) {
				if(nums[y] > nums[x]) break;
				--y;
			}
			int temp = nums[y];
			nums[y] = nums[x];
			nums[x] = temp;
			y = nums.size()-1;
			++x;
			while(x < y) {
				int temp = nums[x];
				nums[x] = nums[y];
				nums[y] = temp;
				++x, --y;
			}
		}
	}
};
