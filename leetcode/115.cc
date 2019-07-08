class Solution {
public:
	int numDistinct(string s, string t) {
		unsigned int n = s.size(), m = t.size();
		if(!m || !n || n < m) return 0;
		if(s == t) return 1;
		vector<unsigned int> f(m, 0);
		for(auto c : s) {
			for(int i = m-1; i > 0; --i) 
				if(c == t[i]) f[i] += f[i-1];
			if(c == t[0]) ++f[0];
		}
		return f[m-1];
	}
};
