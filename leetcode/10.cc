class Solution {
public:

  void search(string s, string p, int x, int y) {
    if(x >= s.size()) {
      if(y >= p.size()) return;
      while(y < p.size()) {
        if(!(p[y] >= 'A' && p[y] <= 'Z') && p[y] != '*') return; 
        ++y;
      }
      ans = true;
      return;
    } 
    if(s[x] == p[y] || p[y] == '.') search(s, p, x+1, y+1);
    else if(p[y] - 'A' == s[x] - 'a' || p[y] == '*') {
      search(s, p, x+1, y);
      search(s, p, x, y+1);
    }
    else if(p[y] >= 'A' && p[y] <= 'Z') search(s, p, x, y+1);

    if((s[x] == p[y] || p[y] == '.' || p[y] - 'A' == s[x] - 'a' || p[y] == '*') 
        && (x == s.size()-1 && y == p.size()-1)) 
      ans = true;
  }

  bool isMatch(string s, string p) {
    string pattern;
    ans = false;
    for(int i = 0; i < p.size(); ++i) {
      if(i+1 < p.size() && p[i+1] == '*') {
        if(p[i] >= 'a' && p[i] <= 'z') pattern += p[i] - 'a' + 'A', ++i;
        else ++i, pattern += p[i];
      }
      else pattern += p[i]; 
    }
    if(s.empty() && pattern.empty()) return true;
    search(s, pattern, 0, 0);
    return ans;
  }
  bool ans;
};


// dp
// from back to front to match s with p
// 20min
class Solution {
public:
  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    bool dp[2][m+1];
    // Note how to deal with boundary conditions
    dp[n%2][m] = true;
    for(int i = n; i >= 0; --i) {
      for(int j = m; j >= 0; --j) {
        if(i == n && j == m) continue;
        // Note how to deal with boundary conditions
        bool match = i < n && j < m && (s[i] == p[j] || p[j] == '.'); 
        if(j < m-1 && p[j+1] == '*')
          dp[i%2][j] = dp[i%2][j+2] || (match && dp[(i+1)%2][j]);
        else 
          dp[i%2][j] = match && dp[(i+1)%2][j+1];
      }
    }
    return dp[0][0];
  }
};
