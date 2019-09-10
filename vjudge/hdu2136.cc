#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 1000005;
/*
void gen_primes(vector<int>& primes, int n) {
  int m = (int)sqrt(n+0.5); 
  vector<int> vis(n+1, 0);
  primes.clear();
  for(int i = 2; i <= m; ++i) if(!vis[i])
    for(int j = i*i; j <= n; j += i) vis[j] = 1;
  for(int i = 2; i <= m; ++i) 
    if(!vis[i]) primes.push_back(i);
}
*/

void gen_primes(vector<int>& cnt, int n) {
  vector<int> vis(n+1, 0);
  cnt.resize(n+1, 0);
  int p = 0;
  for(int i = 2; i <= n; ++i) if(!vis[i]) {
    cnt[i] = ++p; 
    for(int j = 2*i; j <= n; j += i) {
      cnt[j] = p;
      vis[j] = 1;
    }
  }
}


int main() {
  int n;
  vector<int> cnt;
  gen_primes(cnt, maxn);
  while(~scanf("%d\n", &n)) {
    printf("%d\n", cnt[n]);
  }
  return 0;
}
