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

struct Path{
	int pre,pid,ncnt,hcnt,id;
	bool operator < (const Path &x) const{
		if(hcnt == x.hcnt) return ncnt < x.ncnt;
		else return hcnt > x.hcnt;
	}
}paths[220][220];

int dist[220],vis[220],g[220][220],pcnt[220];
int hap[220];
int n,k,start,dest;
char node[220][5];
int tag[303030];
char s[5],t[5];

int change(char *x){
	int ans;
	ans = (x[0]-'A') + (x[1]-'A')*30 + (x[2]-'A')*900;
	return ans;
}

void dij(){
	int i,j,p;
	for(i=1; i<n; i++) dist[i] = INF;
	dist[0] = 0;
	memset(vis, 0 ,sizeof(vis));
	memset(pcnt, 0 ,sizeof(pcnt));
	paths[0][0].pre = -1;
	paths[0][0].pid = 0;
	paths[0][0].ncnt = 1;
	paths[0][0].hcnt = 0;
	paths[0][0].id = 0;
	pcnt[0] = 1;
	int mmin,now;
	while(1){
		mmin = INF;
		for(i=0; i<n; i++) if(!vis[i] && mmin > dist[i]) mmin = dist[now=i];
		if(mmin==INF || now==dest) break;
		vis[now] = 1;
		for(i=0; i<n; i++){
			if(!vis[i] && g[now][i] && dist[i] >= dist[now] + g[now][i]){
				if(dist[i] > dist[now] + g[now][i])  pcnt[i] = 0;
				dist[i] = dist[now] + g[now][i];
				for(j=0,p=pcnt[i]; j<pcnt[now]; j++,p++){
					paths[i][p].pre = now;
					paths[i][p].pid = j;
					paths[i][p].id = i;
					paths[i][p].hcnt = paths[now][j].hcnt + hap[i];
					paths[i][p].ncnt = paths[now][j].ncnt + 1;
				}
				pcnt[i] = p;
			}
		}
	}
	
}

int main(){
//	freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,t1,t2;
	scanf("%d%d%s",&n,&k,node[0]);
	tag[change(node[0])] = 0;
	for(i=1; i<n; i++){
		scanf("%s%d",node[i],&hap[i]);
		tag[change(node[i])] = i;
	}
	dest = tag[change("ROM")];
	for(i=0; i<k; i++){
		scanf("%s%s%d",s,t,&j);
		g[tag[change(s)]][tag[change(t)]] = g[tag[change(t)]][tag[change(s)]] = j;
	}
	dij();
	sort(paths[dest], paths[dest]+pcnt[dest]);
	stack<int> res;
	j = paths[dest][0].hcnt/(paths[dest][0].ncnt-1);
	printf("%d %d %d %d\n", pcnt[dest], dist[dest], paths[dest][0].hcnt, j);
	i = paths[dest][0].pre;
	j = paths[dest][0].pid;
	res.push(dest);
	while(i!=-1){
		res.push(i);
		t1 = paths[i][j].pre;
		t2 = paths[i][j].pid;
		i = t1;
		j = t2;
	}
	while(!res.empty()) printf("%s%s", node[res.top()], res.size()==1 ? "\n" : "->"), res.pop();
	
	return 0;
}
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

struct Path{
	int pre,pid,ncnt,hcnt,id;
	bool operator < (const Path &x) const{
		if(hcnt == x.hcnt) return ncnt < x.ncnt;
		else return hcnt > x.hcnt;
	}
}paths[220][220];

int dist[220],vis[220],g[220][220],pcnt[220];
int hap[220];
int n,k,start,dest;
char node[220][5];
int tag[303030];
char s[5],t[5];

int change(char *x){
	int ans;
	ans = (x[0]-'A') + (x[1]-'A')*30 + (x[2]-'A')*900;
	return ans;
}

void dij(){
	int i,j,p;
	for(i=1; i<n; i++) dist[i] = INF;
	dist[0] = 0;
	memset(vis, 0 ,sizeof(vis));
	memset(pcnt, 0 ,sizeof(pcnt));
	paths[0][0].pre = -1;
	paths[0][0].pid = 0;
	paths[0][0].ncnt = 1;
	paths[0][0].hcnt = 0;
	paths[0][0].id = 0;
	pcnt[0] = 1;
	int mmin,now;
	while(1){
		mmin = INF;
		for(i=0; i<n; i++) if(!vis[i] && mmin > dist[i]) mmin = dist[now=i];
		if(mmin==INF || now==dest) break;
		vis[now] = 1;
		for(i=0; i<n; i++){
			if(!vis[i] && g[now][i] && dist[i] >= dist[now] + g[now][i]){
				if(dist[i] > dist[now] + g[now][i])  pcnt[i] = 0;
				dist[i] = dist[now] + g[now][i];
				for(j=0,p=pcnt[i]; j<pcnt[now]; j++,p++){
					paths[i][p].pre = now;
					paths[i][p].pid = j;
					paths[i][p].id = i;
					paths[i][p].hcnt = paths[now][j].hcnt + hap[i];
					paths[i][p].ncnt = paths[now][j].ncnt + 1;
				}
				pcnt[i] = p;
			}
		}
	}
	
}

int main(){
//	freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,t1,t2;
	scanf("%d%d%s",&n,&k,node[0]);
	tag[change(node[0])] = 0;
	for(i=1; i<n; i++){
		scanf("%s%d",node[i],&hap[i]);
		tag[change(node[i])] = i;
	}
	dest = tag[change("ROM")];
	for(i=0; i<k; i++){
		scanf("%s%s%d",s,t,&j);
		g[tag[change(s)]][tag[change(t)]] = g[tag[change(t)]][tag[change(s)]] = j;
	}
	dij();
	sort(paths[dest], paths[dest]+pcnt[dest]);
	stack<int> res;
	j = paths[dest][0].hcnt/(paths[dest][0].ncnt-1);
	printf("%d %d %d %d\n", pcnt[dest], dist[dest], paths[dest][0].hcnt, j);
	i = paths[dest][0].pre;
	j = paths[dest][0].pid;
	res.push(dest);
	while(i!=-1){
		res.push(i);
		t1 = paths[i][j].pre;
		t2 = paths[i][j].pid;
		i = t1;
		j = t2;
	}
	while(!res.empty()) printf("%s%s", node[res.top()], res.size()==1 ? "\n" : "->"), res.pop();
	
	return 0;
}
