class Solution {
public:
	string minWindow(string s, string t) {
		int f[257], n = t.size(), start = 0, ans_start = 0, ans = INT_MAX;
		memset(f, 0, sizeof(int)*257);
		for(int i = 0; i < t.size(); ++i) ++f[t[i]];
		for(int i = 0; i < s.size();) {
			if(f[s[i+1]]-- > 0) --n;	
			while(n == 0) {
				if(i-start < ans) ans = i-(ans_start=start);
				if(f[s[start++]]++ == 0) ++n;
			}
		}
		return ans == INT_MAX ? "" : s.substr(ans_start, ans);
	}
};

