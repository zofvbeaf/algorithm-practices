#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int n, v;
  while(~scanf("%d%d", &n, &v)) {
    vector<int> value(n);
    vector<int> volume(n);
    vector<int> dp(v+1, 0);
    for(int i = 0; i < n; ++i)
      scanf("%d%d", &volume[i], &value[i]);
    for(int i = 0; i < n; ++i) 
      for(int j = v; j >= volume[i]; --j)
        dp[j] = max(dp[j], dp[j-volume[i]] + value[i]);
    printf("%d\n", dp[v]);
  }
  return 0;
}
