// dp
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		int start = 0, len = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j <= i; ++j) {
				if(i-j < 2) dp[j][i] = s[i] == s[j]; 
				else if(s[i] == s[j]) dp[j][i] = dp[j+1][i-1];
				if(dp[j][i] && i-j+1 > len) {
					start = j, len = i-j+1;
				}
			}
		}
		return s.substr(start, len);
	}
};

// manacher

