#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int INF = 1<<30;
const int maxn = 1e7 + 10;
int g[62][130][1288];
int fa[maxn], cnt[maxn], n, m, l, t, ans, tot;

int get(int x){
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}

int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	scanf("%d%d%d%d", &n, &m, &l,&t);
	for(int i=1; i<=l; i++) for(int j=1; j<=n; j++) for(int k=1; k<=m; k++) {
		scanf("%d",&g[i][j][k]);
		if(g[i][j][k]){
			 g[i][j][k] = ++tot;
			 fa[tot] = tot;
		}
	}
	for(int i=1,x,y; i<=l; i++) for(int j=1; j<=n; j++) for(int k=1; k<=m; k++){
		if(!g[i][j][k]) continue;
		x = get(g[i][j][k]);
		y = get(g[i - 1][j][k]);
		if (y) fa[y] = x;
		y = get(g[i][j - 1][k]);
		if (y) fa[y] = x;
		y = get(g[i][j][k - 1]);
		if (y) fa[y] = x;
	}	
	for(int i=1,x,y; i<=l; i++) for(int j=1; j<=n; j++) for(int k=1; k<=m; k++){
		g[i][j][k] = get(g[i][j][k]);
		cnt[g[i][j][k]]++;
	}
	for (int i = 1; i <= tot; i++) if (cnt[i] >= t) ans += cnt[i];
	printf("%d\n", ans);
	return 0;
}
