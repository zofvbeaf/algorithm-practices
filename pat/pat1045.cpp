#include<cstdio>
using namespace std;

int main()
{
    int m,l,M[202],L,dp[202];
    scanf("%*d%d",&m);
    dp[0] = 0;
    for(int i=0; i<m; i++) dp[i+1] = 0, scanf("%d",M+i);
    scanf("%d",&l);
    while(l--) {
        scanf("%d",&L);
        for(int i=0; i<m; i++)
            if(L == M[i]) dp[i+1]++;
            else dp[i+1] = dp[i] > dp[i+1] ? dp[i] : dp[i+1];
    }
    printf("%d\n",dp[m]);
	return 0;
}
