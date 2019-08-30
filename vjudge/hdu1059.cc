#include <algorithm>
#include <vector>
#include <cstdio>
#include <string.h>

using namespace std;

const int maxn = 120005;

int main() {
  int a[7];
  int dp[maxn];
  int V = 0, ca = 0;
  while(1) {
    V = 0;
    ++ca;
    for(int i = 1; i <= 6; ++i) {
      scanf("%d", &a[i]);
      V += a[i]*i;
    }
    if(V == 0) return 0;
    if(V%2) {
      printf("Collection #%d:\nCan't be divided.\n\n", ca);
      continue;
    }
    V /= 2;
    memset(dp, 0, maxn*sizeof(int));
    for(int i = 1; i <= 6; ++i) {
      if(a[i] == 0) continue;
      if(a[i]*i < V) { // 有限背包
        int k = 1;
        while(k < a[i]) { // 二进制优化
          for(int j = V; j >= k*i; --j)
            dp[j] = max(dp[j], dp[j-k*i] + k*i);
          a[i] -= k;
          k += k;
        }
        for(int j = V; j >= a[i]*i; --j)
          dp[j] = max(dp[j], dp[j-a[i]*i] + a[i]*i);
      }
      else { // 完全背包
        for(int j = i; j <= V; ++j)
          dp[j] = max(dp[j], dp[j-i]+i);
      }
    }
    if(dp[V] == V) 
      printf("Collection #%d:\nCan be divided.\n\n", ca);
    else
      printf("Collection #%d:\nCan't be divided.\n\n", ca);
  }
  return 0;
}