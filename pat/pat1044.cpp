#include<cstdio>
using namespace std;

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    int a[n+1],sum[n+1];
    a[0] = sum[0] = 0;
    for(i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    int ans = sum[n];
    for(i=1,j=1; i<=n; i++){
        while(sum[j]-sum[i-1] < m && j<=n) j++;
        if(sum[j]-sum[i-1]>=m && sum[j]-sum[i-1] < ans) ans = sum[j]-sum[i-1];
    }
    for(i=1,j=1; i<=n; i++){
        while(sum[j]-sum[i-1]<ans && j<=n) j++;
        if(sum[j]-sum[i-1]==ans) printf("%d-%d\n",i,j);
    }
	return 0;
}
