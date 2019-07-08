class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    int x = 0, y = 0;
    int star = -1;
    int lastx = 0;
    while(x < n) {
      if(s[x] == p[y] || p[y] == '?') ++x, ++y;
      else if(y < m && p[y] == '*') star = y++, lastx = x;
      else if(star > -1) x = ++lastx, y = star + 1;
      else return false;
    }
    while(y < m && p[y] == '*') ++y;
    return y == m;
  }
};

// dp solution
class Solution {
public:

  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    bool dp[2][m+1];    
    dp[n%2][m] = true;
    for(int i = n; i >= 0; --i)
      for(int j = m; j >= 0; --j) {
        if(i == n && j == m) continue;
        bool match = i < n && j < m && (s[i] == p[j] || p[j] == '?' || p[j] == '*');
        if(j < m && p[j] == '*')
          dp[i%2][j] = dp[i%2][j+1] || (match && dp[(i+1)%2][j]);
        else
          dp[i%2][j] = match && dp[(i+1)%2][j+1];
      }
    return dp[0][0];
  }
};
