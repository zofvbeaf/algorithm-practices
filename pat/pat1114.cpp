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
const int maxn = 1e4 + 2;

int n,tot,es[maxn],ar[maxn],g[maxn][maxn],vis[maxn];
int mid[maxn],cnt[maxn],ces[maxn],car[maxn],a[maxn];
double avear[maxn];
void dfs(int x){
	vis[x] = 0;
	if(mid[tot] > x) mid[tot] = x;
	cnt[tot]++;
	ces[tot] += es[x];
	car[tot] += ar[x];	
	for(int i=0; i<maxn; i++) if(g[x][i] && vis[i]==1) dfs(i);
}

bool comp(const int &x, const int &y){
	return avear[x]==avear[y] ? mid[x] < mid[y] : avear[x] > avear[y];
}

int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	scanf("%d",&n);
	for(int i=0,x,y,z; i<n; i++){
		scanf("%d%d%d",&x,&y,&z);
		vis[x] = 1;
		if(y!=-1) g[x][y] = g[y][x] = 1,vis[y] = 1;
		if(z!=-1) g[x][z] = g[z][x] = 1,vis[z] = 1;;
		scanf("%d",&y);
		while(y--) scanf("%d",&z), g[x][z] = g[z][x] = 1, vis[z]=1;
		scanf("%d%d",&es[x],&ar[x]);
	}
	for(int i=0; i<maxn; i++){
		if(vis[i]==1){
			mid[tot]=INF, a[tot]=tot;
			dfs(i);
			avear[tot] = car[tot]*1.0/cnt[tot];
			tot++;
		} 
		
	}
	printf("%d\n",tot);
	sort(a,a+tot,comp);
	for(int i=0; i<tot; i++) 
		printf("%04d %d %.3lf %.3lf\n", mid[a[i]], cnt[a[i]], ces[a[i]]*1.0/cnt[a[i]], avear[a[i]]);
	return 0;
}
