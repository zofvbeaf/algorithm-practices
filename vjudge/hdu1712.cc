#include <algorithm>
#include <vector>
#include <cstdio>
#include <string.h>
#include <unordered_map>

using namespace std;

int main() {
  freopen("in.txt", "r", stdin);
  int n, m, x;
  while (~scanf("%d%d", &n, &m) && (n || m)) {
    vector<int> dp(m+1, 0);
    vector<int> a(m+1, 0);
    for(int i = 1; i <= n; ++i) {
      for(int j = 1; j <= m; ++j) scanf("%d", &a[j]);
      for(int v = m; v >= 1; --v) {
        for(int j = 1; j <= v; ++j) {
          dp[v] = max(dp[v], dp[v-j]+a[j]);
        }
      }
    }
    printf("%d\n", dp[m]);
  }
  return 0;
}