class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
	  int pos[400];
	  int dp[400];
	  memset(dp, 0, sizeof(int)*400);
	  memset(pos, 0, sizeof(int)*400);

	  for(int i = 0; i < days.size(); ++i) days[i] += 30;

	  dp[days[0]] = costs[0]; 

	  for(int i = 1; i < days.size(); ++i) {
      for(int j = days[i-1]; j < days[i]; ++j) 
        pos[j] = days[i-1];

      dp[days[i]] = min(dp[pos[days[i]-1]]+costs[0], 
          min(dp[pos[days[i]-7]]+costs[1], dp[pos[days[i]-30]]+costs[2]));
	  }
    return dp[days.back()]; 
	}
};
