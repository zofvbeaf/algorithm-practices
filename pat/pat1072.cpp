#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>
#include<functional>
using namespace std;
const int INF = 1<<30;

// struct station{
	// int id;
	// int ave,mindist;
// }gas[15];

int n,m,k,d,vis[1050],g[1050][1050],dist[1050];
int ans,tot,id;
void dij(int x){
	// x -= n;
	int i;
	// gas[x].mindist = INF;
	// gas[x].ave = 0;
	// gas[x].id = x;
	memset(vis,0,sizeof(vis));
	memset(dist,-1,sizeof(dist));
	dist[x] = 0;
	int now;
	while(1){
		now = -1;
		for(i=1; i<=n+m; i++){
			if(vis[i] || dist[i]==-1) continue;
			if(now==-1 || dist[i] < dist[now]) now = i;
		}
		if(now==-1) break;
		vis[now] = 1;
		for(i=1; i<=n+m; i++){
			if(g[now][i]){
				if(dist[i]==-1 || dist[i] > dist[now]+g[now][i]) dist[i] = dist[now]+g[now][i];
			}
		}
	}
	int mindis = INF, sumdis = 0;
	for(i=1; i<=n; i++){
		if(dist[i]==-1 || dist[i]>d) return;
		mindis = mindis < dist[i] ? mindis : dist[i];
		sumdis += dist[i];
	}
	if(ans < mindis) ans = mindis, tot = sumdis, id = x-n;
	else if(ans==mindis && tot > sumdis) tot = sumdis, id = x-n;
	
	// for(i=1; i<=n; i++){
		// if(dist[i]==-1 || dist[i]>d){
			// gas[x].ave = INF;
			// gas[x].mindist = INF;
			// return;
		// }
		// gas[x].mindist = gas[x].mindist < dist[i] ? gas[x].mindist : dist[i];
		// gas[x].ave += dist[i];
	// }
}

// bool comp(station a, station b){
	// if(a.mindist == b.mindist){
		// if(a.ave == b.ave) return a.id < b.id;
		// else return a.ave < b.ave;
	// }
	// else return a.mindist > b.mindist;
// }

int change(char* s){
	int ans = 0;
	for(int i= s[0]=='G'; s[i]; i++)  ans = ans*10 + (s[i]-'0');
	if(s[0]=='G') ans += n;
	return ans;
}

int main(){
 //freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,ss,tt,j;
	char s[10],t[10];
	scanf("%d%d%d%d",&n,&m,&k,&d);
	for(i=0; i<k; i++){
		scanf("%s %s %d",s,t,&j);
		ss = change(s);
		tt = change(t);
		if(j<=d) g[ss][tt] = g[tt][ss] = j;
	}
	ans = 0; tot = INF;
	for(i=n+1; i<=n+m; i++) dij(i);
	if (!ans) printf("No Solution\n");
	else printf("G%d\n%.1lf %.1lf\n", id, (double)ans, (double)tot / n);
	// sort(gas+1, gas+m+1, comp);
	// if(gas[1].mindist == INF) printf("No Solution\n");
	// else printf("G%d\n%.1lf %.1lf\n",gas[1].id, (double)gas[1].mindist, (double)gas[1].ave/n);
	return 0;
}
