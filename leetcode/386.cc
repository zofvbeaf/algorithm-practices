class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> ans;
	  if(n) ans.push_back(1);
	  int now = 1;
		--n;
		while(n-- > 0)
		  ans.push_back(ans.back()*10 <= n ? ans.back()*10 : (ans.back() + 1 <= n ? ans.back() + 1 : ++now));
		return ans;
	}
};
