#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int T, n, v;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &n, &v);
    vector<int> value(n);
    vector<int> volume(n);
    vector<int> dp(v+1, 0);
    for(int i = 0; i < n; ++i) scanf("%d", &value[i]);
    for(int i = 0; i < n; ++i) scanf("%d", &volume[i]);
    for(int i = 0; i < n; ++i) 
      for(int j = v; j >= volume[i]; --j)
        dp[j] = max(dp[j], dp[j-volume[i]] + value[i]);
    printf("%d\n", dp[v]);
  }
  return 0;
}
