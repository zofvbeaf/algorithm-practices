#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n, m, x, y;
    int dp[200000];
    while(~scanf("%d%d", &n, &m)){
        memset(dp, 0, sizeof(dp));
        while(n--){
            scanf("%d%d", &x, &y);
            for(int v=x; v<=m; v++)
                dp[v] = max(dp[v], dp[v-x]+y);
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}