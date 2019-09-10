#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int main() {
  int n, m;
  int x, ans;
  vector<int> a;
  while(~scanf("%d%d", &n, &m)) {
    a.clear();
    ans = 0;
    for(int i = 0; i < m; ++i) {
      scanf("%d", &x);
      if(x) a.push_back(x);
    }
    m = a.size();
    for(int i = 0; i < (1<<m); ++i) {
      int lcm = -1;
      int cnt = 0;
      for(int j = 0; j < m; ++j) {
        if(i & (1<<j)) {
          if(lcm == -1) lcm = a[j];
          else lcm = lcm/gcd(lcm, a[j])*a[j];
          ++cnt;
        }
      }
      if(lcm == -1) continue;
      if(cnt & 1) ans += (n-1)/lcm;
      else ans -= (n-1)/lcm;
    }
    printf("%d\n", ans);
  }
  return 0;
}
