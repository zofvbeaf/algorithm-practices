// dp[i][j] 表示耐久度为 i 时杀 j 个怪可获得的最大经验值
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string.h>
#include <climits>

using namespace std;

int main() {
  freopen("in.txt", "r", stdin);
  int n, m, k, s, a, b, ans;
  while(~scanf("%d%d%d%d", &n, &m, &k, &s)) {
    vector<vector<int> > dp(n+1, vector<int>(s+1, 0));
    ans = INT_MAX;
    while(k--) {
      scanf("%d%d", &a, &b);
      for(int i = b; i <= m; ++i) {
        for(int j = 1; j <= s; ++j) {
          dp[i][j] = max(dp[i][j], dp[i-b][j-1]+a);
          if(dp[i][j] >= n && i < ans) ans = i;
        }
      }
    }
    if(ans == INT_MAX) ans = -1;
    else ans = m - ans;
    printf("%d\n", ans);
  }
  return 0;
}