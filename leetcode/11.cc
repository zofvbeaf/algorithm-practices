// 11min
class Solution {
public:
	int maxArea(vector<int>& height) {
		int ans = 0, s = 0, e = height.size()-1;
		while(s < e) {
			ans = max(ans, (e-s)*(min(height[s], height[e])));
			if(height[s] < height[e]) {
				int hs = height[s];
				while(s < e && height[s] <= hs) ++s; // <=
			}
			else {
				int es = height[e];
				while(s < e && height[e] <= es) --e;
			}
		}
		return ans;
	}
};
