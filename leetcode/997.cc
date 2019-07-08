class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		int f[1005][2];
		memset(f, 0, sizeof(int)*1005*2);
		for(int i = 0; i < trust.size(); ++i) {
			++f[trust[i][1]][0];
			++f[trust[i][0]][1];
		}
		int ans = -1;
		for(int i = 1; i <= N; ++i) {
			if(f[i][0] == N-1 && !f[i][1]) {
				if(ans < 0) ans = i;
				else return -1;
			}
		}
		return ans;
	}
};
