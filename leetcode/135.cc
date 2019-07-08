class Solution {
public:
	int candy(vector<int>& ratings) {
    int ans = ratings.size();
    vector<int> temp(ans, 0);
    if(ans < 2) return ans;
    temp[0] = (ratings[0] > ratings[1] ? 1 : 0);
    ans += temp[0];
    for(int i = 1; i < ratings.size(); ++i) {
      if(ratings[i] > ratings[i-1]) 
        temp[i] = temp[i-1] + 1, ans += temp[i]; 
    }
    for(int i = ratings.size()-1; i > 0; --i) {
      if(ratings[i-1] > ratings[i] && temp[i-1] <= temp[i])
        ans += temp[i] + 1 - temp[i-1], temp[i-1] = temp[i] + 1; 
    }
    return ans;
	}
};
