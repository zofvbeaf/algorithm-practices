#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
  int n, m, maxv_index, temp;
  while(~scanf("%d", &n) && n) {
    vector<int> volume(n);
    maxv_index = 0;
    for(int i = 0; i < n; ++i) {
      scanf("%d", &volume[i]);
      if(volume[i] > volume[maxv_index]) maxv_index = i;
    }
    scanf("%d", &m);
    if(m < 5) {
      printf("%d\n", m);
      continue;
    }
    vector<int> dp(m+1, 0);
    temp = volume[maxv_index];
    volume[maxv_index] = m + 1;
    m -= 5; // 找出最贵的菜，花5元买之
    for(int i = 0; i < n; ++i) 
      for(int j = m; j >= volume[i]; --j)
        dp[j] = max(dp[j], dp[j-volume[i]] + volume[i]);
    printf("%d\n", m + 5 - (temp + dp[m]));
  }
  return 0;
}
