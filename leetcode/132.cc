class Solution {
public:
  int minCut(string s) {
    int ans = s.size();
    vector<bool> is_palindrome(s.size(), false);
    vector<int> min_cut(s.size(), 0);
    for(int i = 0, x = i; i < s.size(); ++i) {
      x = i;
      for(int j = 0; j <= i; ++j) {
        if(s[j] == s[i] && (j >= i-1 || is_palindrome[j+1])) { // s[j+1, i-1] is_palindrome
          is_palindrome[j] = true;
          x = (j == 0) ? 0 : min(x, min_cut[j-1]+1);
        }
        else 
          is_palindrome[j] = false;
      }
      min_cut[i] = x;
    }
    return min_cut.back();
  }
};
