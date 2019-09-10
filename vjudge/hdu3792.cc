#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 100005;

void gen_cnt(vector<int>& cnt, vector<int>& vis, int n) {
  int m = (int)sqrt(n+0.5); 
  vis.resize(n+1, 0);
  cnt.resize(n+1, 0);
  for(int i = 2; i <= m; ++i) if(!vis[i])
    for(int j = i*i; j <= n; j += i) vis[j] = 1;
  vis[0] = vis[1] = 1;
  for(int i = 2; i <= n; ++i) 
    cnt[i] = cnt[i-1] + (vis[i] == 0 && vis[i-2] == 0);
}

int main() {
  int n;
  vector<int> cnt, vis;
  gen_cnt(cnt, vis, maxn);
  while(~scanf("%d\n", &n) && n >= 0) {
    printf("%d\n", cnt[n]);
  }
  return 0;
}
