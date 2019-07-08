#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<math.h>
#include<functional>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
const int maxn = 30;

int n,t[maxn][2],v[maxn],tag[maxn],pre[maxn];
int deep = 0;
void dfs(int x, int l){
	if(x==-1) return;
	tag[l] = 1;
	v[l] = x;
	dfs(t[x][0], 2*l+1);
	dfs(t[x][1], 2*l+2);
}

int main(){
	char x[5],y[5];
	scanf("%d",&n);
	memset(pre,-1,sizeof(pre));
	for(int i=0,j; i<n; i++){
		scanf("%s%s",&x,&y);
		if(x[0]!='-') sscanf(x,"%d",&j), t[i][0] = j, pre[j] = i;
		else t[i][0] = -1;
		if(y[0]!='-') sscanf(y,"%d",&j), t[i][1] = j, pre[j] = i;
		else t[i][1] = -1;
	} 
	int root;
	for(root=0; root<n; root++) if(pre[root]==-1) break;
	dfs(root,0);
	for(int i=0; i<n; i++){
		if(!tag[i]){
			printf("NO %d\n",root);
			return 0;
		}
	}
	printf("YES %d\n",v[n-1]);
	return 0;
}
