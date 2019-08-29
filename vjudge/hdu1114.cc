// 给出存钱罐本身的重量和装钱后的重量，以及存钱罐中钱的面值和重量，
// 求存钱罐装满时，钱的总和最小是多少
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

const int maxn = 1<<30;

int main() {
  int T, E, F, n, V, p, w;
  scanf("%d", &T);
  while(T--) {
    scanf("%d%d", &E, &F);
    V = F - E;
    scanf("%d", &n);
    vector<int> a(n, 0);
    vector<int> dp(V+1, maxn);
    dp[0] = 0;
    for(int i = 0; i < n; ++i) {
      scanf("%d%d", &p, &w);
      for(int j = w; j <= V; ++j)
        dp[j] = min(dp[j], dp[j-w]+p);
    }
    if(dp[V] == maxn) 
      printf("This is impossible.\n");
    else
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[V]);
  }
  return 0;
}
