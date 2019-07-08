#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include<functional>
using namespace std;
typedef long long LL;
const int INF = 1<<30;

vector<int> g[110];
int n,m;
int ans[110];

void bfs(int x, int l){
	ans[l]++;
	for(int i=0; i<g[x].size(); i++) bfs(g[x][i], l+1);
}

int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,k;
	memset(ans, 0, sizeof(ans));
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d",&i,&j);
		while(j--) scanf("%d",&k), g[i].push_back(k);
	}
	bfs(1,1);
	j = 1;
	for(i=2; i<110; i++) if(ans[j] < ans[i]) j = i;
	printf("%d %d\n",ans[j], j);
	return 0;
}
