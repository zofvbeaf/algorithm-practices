class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    bool dp[2][m+1];    
    dp[n%2][m] = true;
    for(int i = n; i >= 0; --i)
      for(int j = m; j >= 0; --j) {
        if(i == n && j == m) continue;
        bool match = i < n && j < m && (s[i] == p[j] || p[j] == '.');
        if(j < m-1 && p[j+1] == '*')
          dp[i%2][j] = dp[i%2][j+2] || (match && dp[(i+1)%2][j]);
        else
          dp[i%2][j] = match && dp[(i+1)%2][j+1];
      }
    return dp[0][0];
  }
};
