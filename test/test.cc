#include <bits/stdc++.h>

int flag[100005];

int find(int x) {
  return (flag[x] == x) ? x : (flag[x] = find(flag[x]));
}

int main() {
  int n, m, x, y;
  std::string s;
  std::cin >> n >> m >> s;
  for(int i = 1; i <= n; ++i) {
    flag[i] = i;
  }
  std::vector<int> ans;
  for(int i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    if(s[x-1] == s[y-1]) continue;
    int a = find(x), b = find(y);
    if(a > b) {
      flag[a] = b; 
      ans.push_back(i);
    }
    else if(a < b) {
      flag[b] = a; 
      ans.push_back(i);
    }
  }
  printf("%d\n", ans.size());
  for(int i = 0; i < ans.size(); ++i)
    printf("%d%s", ans[i], (i == ans.size()-1) ? "\n" : " ");
    
  return 0;
}
