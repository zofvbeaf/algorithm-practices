#include <cstdio>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
  return a/gcd(a, b)*b;
}

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  vector<int> a(n+1, 0);
  for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for(int i = 1; i <= n; ++i) {
    if(a[i] < 0) continue;
    int now = a[i], cnt = 1;
    while(1) {
      if(now == i || now < 0) break;
      now = a[now];
      ++cnt;
    }
    if(ans == 0) ans = cnt;
    else ans = lcm(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}
