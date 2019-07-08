class Solution {
public:
	int maxProfit(vector<int>& prices) {
	  int t = 0, s = 0, x = 0, y = 0;
	  if(prices.size() < 2) return 0;
    for(int i = 1; i < prices.size(); ++i) {
      if(prices[i] < prices[i-1]) {
        t = prices[i-1] - prices[s];  
        if(t > x) y = x, x = t;
        else if(t > y) y = t;
        s = i;
      }
    }
    if(prices.back() - prices[s] > y) 
      return x + prices.back() - prices[s];
    return x + y;
	}
};
