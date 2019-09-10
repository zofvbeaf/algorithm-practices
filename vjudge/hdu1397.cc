#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 1<<15;

void gen_primes(vector<int>& primes, vector<int>& vis, int n) {
  int m = (int)sqrt(n+0.5); 
  vis.resize(n+1, 0);
  primes.clear();
  for(int i = 2; i <= m; ++i) if(!vis[i])
    for(int j = i*i; j <= n; j += i) vis[j] = 1;
  for(int i = 2; i <= n; ++i) 
    if(!vis[i]) primes.push_back(i);
}

int main() {
  int n;
  vector<int> primes, vis;
  gen_primes(primes, vis, maxn);
  while(~scanf("%d\n", &n) && n) {
    int ans = 0;
    for(int i = 0; i < primes.size() && primes[i]*2 <= n; ++i) 
      ans += (vis[n-primes[i]] == 0);
    printf("%d\n", ans);
  }
  return 0;
}
