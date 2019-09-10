#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 21;

int main() {
  int T, n, m;
  scanf("%d", &T);
  vector<long long> f(maxn, 0);
  vector<long long> g(maxn, 1);
  f[2] = 1;
  g[2] = 2;
  for(int i = 3; i < maxn; ++i) {
    f[i] = (i-1)*(f[i-1] + f[i-2]); 
    g[i] = g[i-1]*i;
  }
  while(T--) {
    scanf("%d%d", &n, &m);
    printf("%lld\n", g[n]/g[m]/g[n-m]*f[m]); 
  }
  return 0;
}
