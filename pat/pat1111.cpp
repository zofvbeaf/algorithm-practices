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
const int maxn = 550;

struct Path_dist{
	int pre,pid,len,tim;
}p1[maxn][maxn];

struct Path_time{
	int pre,pid,num,tim;
}p2[maxn][maxn];

int g[maxn][maxn],vis[maxn],dist[maxn],tim[maxn][maxn],pcnt[maxn];
int n,m,s,t;

void dij_dist(){
	for(int i=0; i<n; i++) dist[i] = INF, vis[i] = 0, pcnt[i] = 0;
	dist[s] = 0;
	pcnt[s] = 1;
	p1[s][0].pre = -1;
 	int mmin,now;
	while(1){
		mmin = INF;
		for(int i=0; i<n; i++) if(!vis[i] && mmin > dist[i]) mmin = dist[now=i];
		if(now==t) return;
		vis[now] = 1;
		for(int i=0; i<n; i++){
			if(!vis[i] && g[now][i]){
				if(dist[i] >= g[now][i]+dist[now]){
					if(dist[i] > g[now][i]+dist[now]) pcnt[i] = 0;
					dist[i] = g[now][i]+dist[now];
					int k=pcnt[i];
					for(int j=0; j < pcnt[now]; j++,k++){
						p1[i][k].pre = now;
						p1[i][k].pid = j;
						p1[i][k].len = dist[i];
						p1[i][k].tim = p1[now][j].tim + tim[now][i];
					}
					pcnt[i] = k;
				}
			}
		}
	}
}

void dij_time(){
	for(int i=0; i<n; i++) dist[i] = INF, vis[i] = 0, pcnt[i] = 0;
	dist[s] = 0;
	pcnt[s] = 1;
	p2[s][0].pre = -1;
 	int mmin,now;
	while(1){
		mmin = INF;
		for(int i=0; i<n; i++) if(!vis[i] && mmin > dist[i]) mmin = dist[now=i];
		if(now==t) return;
		vis[now] = 1;
		for(int i=0; i<n; i++){
			if(!vis[i] && tim[now][i]){
				if(dist[i] >= tim[now][i]+dist[now]){
					if(dist[i] > tim[now][i]+dist[now]) pcnt[i] = 0;
					dist[i] = tim[now][i]+dist[now];
					int k=pcnt[i];
					for(int j=0; j < pcnt[now]; j++,k++){
						p2[i][k].pre = now;
						p2[i][k].pid = j;
						p2[i][k].tim = dist[i];
						p2[i][k].num = p2[now][j].num + 1;
					}
					pcnt[i] = k;
				}
			}
		}
	}
}

vector<int> res1;
vector<int> res2;

bool comp(){
	int l1 = res1.size()-1;
	int l2 = res2.size()-1;
	if(l1 != l2) return 0;
	for(int i=0; i<l1; i++) if(res1[i] != res2[i]) return 0;
	return 1;
}

int main(){
	scanf("%d%d",&n,&m);
	int x,y,z;
	while(m--) {
		scanf("%d%d%d",&x,&y,&z);
		scanf("%d%d", &g[x][y], &tim[x][y]);
		if(!z) g[y][x] = g[x][y], tim[y][x] = tim[x][y];
	}
	scanf("%d%d",&s,&t);
	dij_dist();
	x = INF; 
	for(int i=0; i<pcnt[t]; i++) if(x > p1[t][i].tim) x = p1[t][y=i].tim;
	z = t;
	int i=z,j=y;
	while(z!=-1){
		res1.push_back(z);
		i = p1[z][j].pre;
		j = p1[z][j].pid;
		z = i;
	}
	res1.push_back(dist[t]);
	
	dij_time();
	x = INF; 
	for(int i=0; i<pcnt[t]; i++) if(x > p2[t][i].num) x = p2[t][y=i].num;
	z = t;
	i=z,j=y;
	while(z!=-1){
		res2.push_back(z);
		i = p2[z][j].pre;
		j = p2[z][j].pid;
		z = i;
	}
	res2.push_back(dist[t]);
	
	if(!comp()){
		i=res1.size()-1;
		printf("Distance = %d: ",res1[i]);
		i--;
		for(; i>=0; i--) printf("%d%s", res1[i], i ? " -> " : "\n");
		i=res2.size()-1;
		printf("Time = %d: ",res2[i]);
		i--;
		for(; i>=0; i--) printf("%d%s", res2[i], i ? " -> " : "\n");
	}
	else{
		i=res1.size()-1;
		printf("Distance = %d; Time = %d: ",res1[i],res2[i]);
		i--;
		for(; i>=0; i--) printf("%d%s", res1[i], i ? " -> " : "\n");
	}
	return 0;
}
