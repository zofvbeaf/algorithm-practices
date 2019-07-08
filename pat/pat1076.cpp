#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<queue>
#include<math.h>
#include<functional>
using namespace std;
const int INF = 1<<30;
int g[1010][1010],dist[1010];
int n,level;

int bfs(int o){
	queue<int> q;
	int ans = 0;
	q.push(o);
	dist[o]  = 0;
	while(!q.empty()){
		int p = q.front(); q.pop();
		if(dist[p] <= level) ans++; else break;
		for(int i=1; i<=n; i++){
			if(g[p][i] && dist[i] > dist[p]+1){
				dist[i] = dist[p] + 1;
				q.push(i);
			} 
		}
	}
	return ans-1; //因为源点的时候ans也进行了+1
}

int main(){
 // freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,t;
	memset(g, 0, sizeof(g));
	scanf("%d%d",&n,&level);
	for(i=1; i<=n; i++) {
		scanf("%d",&j);
		while(j--){
			scanf("%d",&t);
			g[t][i] = 1;
		}
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d",&j);
		for(i=1; i<=n; i++) dist[i] = INF;
		printf("%d\n",bfs(j));
	}
	return 0;
}
