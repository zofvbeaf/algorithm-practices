class Solution {
public:
  void dfs(string s, int x, int y, vector<string>& ans) {
    if(x < 0 || y < 0 || x < y) return;
    if(!x && !y) ans.push_back(s);
    else if(x > y) dfs(s+'(', x-1, y, ans), dfs(s+')', x, y-1, ans);
    else if(x == y) dfs(s+'(', x-1, y, ans);
  }

  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s;
    dfs("", n, n, ans);
    return ans;
  }
};

int main() {
  Solution sol;
  int n;
  std::cin << n;
  auto ans = sol.generateParenthesis(n);
  for(i : ans) std::cout << i << std::endl;
}
