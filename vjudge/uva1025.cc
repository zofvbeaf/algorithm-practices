#include <vector>
#include <cstdio>

using namespace std;

const int INF = 1<<30;

int main() {
  int n, T, M1, M2, x, kase = 0;
  while(~scanf("%d%d", &n, &T) && n) {
    vector<int> t(n, 0);
    for(int i = 1; i < n; ++i) scanf("%d", &t[i]);
    vector< vector< vector<bool> > > has_train(T+1, vector< vector<bool> >(n+1, vector<bool>(2, false)));
    scanf("%d", &M1);
    while(M1--) {
      scanf("%d", &x);
      for(int i = 1; i < n; ++i) {
        if(x > T) break;
        has_train[x][i][0] = true;
        x += t[i];
      }
    }
    scanf("%d", &M2);
    while(M2--) {
      scanf("%d", &x);
      for(int i = n-1; i >= 0; --i) {
        if(x > T) break;
        has_train[x][i+1][1] = true;
        x += t[i];
      }
    }
    vector<vector<int> > dp(T+1, vector<int>(n+1, INF));
    dp[T][n] = 0;
    for(int i = T-1; i >= 0; --i) {
      for(int j = 1; j <= n; ++j) {
        dp[i][j] = dp[i+1][j] + 1; // 等待一个单位
        if(j < n && has_train[i][j][0] && i + t[j] <= T)
          dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]); // 右
        if(j > 1 && has_train[i][j][1] && i + t[j-1] <= T)
          dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]); // 左
      }
    }
    printf("Case Number %d: ", ++kase);
    if(dp[0][1] >= INF) printf("impossible\n");
    else printf("%d\n", dp[0][1]);
  }

  return 0;
}
