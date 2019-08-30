// k 种物品，每种物品下有多个，价值不同，每种必须至少取一个
// dp[i][j] 表示前 i 种物品花费容量 j 可获得的最大价值
// dp[0][0..m] 取值为0，其余为 -1， 这样为 -1 的对应的物品就表示没有取到
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string.h>
#include <unordered_map>

using namespace std;

struct Node
{
  Node(int p, int v) : price(p), value(v) { } 
  int price, value;
};


int main() {
  freopen("in.txt", "r", stdin);
  int n, m, k;
  int a, b, c;
  while(~scanf("%d%d%d", &n, &m, &k)) {
    unordered_map<int, vector<Node> > nodes;
    for(int i = 0; i < n; ++i) {
      scanf("%d%d%d", &a, &b, &c);
      nodes[a].emplace_back(b, c);
    }
    vector<vector<int> > dp(k+1, vector<int>(m+1, -1));
    for(int i = 0; i <= m; ++i) dp[0][i] = 0;
    for(int i = 1; i <= k; ++i) {
      for(auto& it : nodes[i]) {
        for(int j = m; j >= it.price; --j) {
          if(dp[i][j-it.price] != -1) // 非第一次取
            dp[i][j] = max(dp[i][j], dp[i][j-it.price]+it.value);
          if(dp[i-1][j-it.price] != -1) // 第一次取
            dp[i][j] = max(dp[i][j], dp[i-1][j-it.price]+it.value); 
        }
      }
    }
    if(dp[k][m] < 0) printf("Impossible\n");
    else printf("%d\n", dp[k][m]);
  }
  return 0;
}