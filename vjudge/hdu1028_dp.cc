#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, maxn = 121;
  vector<long long> dp(maxn, 0);
  dp[0] = 1;
  for(int i = 1; i < maxn; ++i) {
    for(int j = i; j < maxn; ++j) {
      dp[j] += dp[j-i];
    }
  }
  while(~scanf("%d", &n)) printf("%lld\n", dp[n]);
  return 0;
}
