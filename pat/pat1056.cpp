#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int w[1010],o[1010],rk[1010],t[1010];
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++) scanf("%d",w+i);
	for(i=1; i<=n; i++) scanf("%d",o+i),o[i]++;
	while(1){
		int tot = 0;
		for(i=1; i<=n; i++) if(!rk[o[i]]) t[++tot] = o[i];
		if(tot==1) { rk[t[1]] = 1; break; }
		for(i=1,j=1; i<=tot; i++){
			if(i%m==0 || i==tot){
				int now = i;
				for(int k=j; k<=i; k++) if(w[t[k]] > w[t[now]]) now = k;
				for(; j<=i; j++) if(j != now) rk[t[j]] = tot/m + (tot%m ? 1 : 0) + 1;
			}
		}
	}
	for(i=1; i<=n; i++) printf("%d%s",rk[i],i==n ? "\n" : " ");
    return 0;
}
