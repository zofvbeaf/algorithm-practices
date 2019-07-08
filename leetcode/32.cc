class Solution {
public:
  int longestValidParentheses(string s) {
    int x = 0, ans = 0;
    for(int i = 0; i < s.size(); ++i) 
      if(s[x] == '(') ++x;
      else if(x > 0) --x, ++ans;
    return ans;
  }
};
