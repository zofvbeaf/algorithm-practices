#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 21;

int main() {
  int T, n;
  scanf("%d", &T);
  vector<double> f(maxn, 0);
  vector<double> g(maxn, 0);
  f[2] = 1.0;
  g[2] = 2.0;
  for(int i = 3; i < maxn; ++i) {
    f[i] = (i-1)*(f[i-1] + f[i-2]); 
    g[i] = g[i-1]*i;
  }
  while(T--) {
    scanf("%d", &n);
    printf("%.2lf%%\n", f[n]/g[n]*100); 
  }
  return 0;
}
