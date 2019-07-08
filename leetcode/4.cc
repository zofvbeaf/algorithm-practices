class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if(nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);
		int m = nums1.size(), n = nums2.size();
		int start = 0, end = m, x = (m+n+1)/2;

		while(start <= end) {
			int i = (start+end)/2, j = x - i;
			if(j > 0 && i < m && nums1[i] < nums2[j-1]) start = i+1;
			else if(i > 0 && j < n && nums1[i-1] > nums2[j]) end = i-1;
			else {
				int max_left = 0, min_right = 0;
				if(i == 0) max_left = nums2[j-1];
				else if(j == 0) max_left = nums1[i-1];
				else max_left = max(nums1[i-1], nums2[j-1]);

				if((m+n)%2) return max_left;

				if(i == m) min_right = nums2[j];
				else if(j == n) min_right = nums1[i];
				else min_right = min(nums1[i], nums2[j]);
				return (max_left+min_right)/2.0;
			}
		}
		return 0.0;
	}
};
