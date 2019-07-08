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
const int maxn = 1e3 + 50;
int n,tot;
int cnt[maxn],vis[maxn];
vector<int> res;
vector<int> g[maxn];
void dfs(int x){
	vis[x] = 0;
	tot += cnt[x];
	for(int i=0; i<g[x].size(); i++){
		if(vis[g[x][i]]==1) dfs(g[x][i]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1,j,x,k; i<=n; i++){
		scanf("%d:",&j);
		k = -1;
		while(j--){
			scanf("%d:",&x);
			if(!vis[x]) vis[x]=1;
			if(k!=-1) g[k].push_back(x),g[x].push_back(k);
			else cnt[x]++;
			k = x; 
		}
	}
	for(int i=1; i<maxn; i++){
		tot = 0;
		if(vis[i]==1) dfs(i);
		if(tot) res.push_back(tot);
	}
	sort(res.begin(), res.end(), greater<int>());
	tot = res.size();
	printf("%d\n",tot);
	for(int i=0; i<tot; i++) printf("%d%s", res[i], i==tot-1 ? "\n" : " ");
	return 0;
}
