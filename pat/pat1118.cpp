#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<functional>
#include<cstring>
using namespace std;

int n,q,cnt,ans,f[10015][10015],a[10015],v[10015],u[10015];

void dfs(int x, int t){
	u[x] = t;
	v[x] = 1; 
	for(int i=0; i<10002; i++){
		if(!v[i] && f[x][i]) dfs(i,t);
	}
}

int main(){
	scanf("%d",&n);
	
	for(int i=0,j,x,y; i<n; i++){
		scanf("%d",&j);
		y = 0;
		while(j--) {
			scanf("%d",&x);
			if(!a[x]) ans++, a[x] = 1;
			if(!y) y = x;
			else f[y][x] = f[x][y] = 1;
		}
	}
	for(int i=0; i<10002; i++){
		if(a[i] && !v[i]){
			dfs(i,i);
			cnt++;
		} 
	}
	printf("%d %d\n", cnt, ans);
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(u[x]==u[y]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
