#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  int n, maxn = 121;
  vector<long long> a(maxn, 0);
  vector<long long> b(maxn, 0);
  a[0] = 1;
  for(int i = 1; i < maxn; ++i) {
    for(int j = 0; j < maxn; j += i) {
      for(int k = 0; j+k < maxn; ++k) {
        b[j+k] += a[k];
      }
    }
    for(int j = 0; j < maxn; ++j) {
      a[j] = b[j];
      b[j] = 0;
    }
  }
  while(~scanf("%d", &n)) printf("%lld\n", a[n]);
  return 0;
}
