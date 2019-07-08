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

int n;
double p,r;
int ta[200000];
vector<int>  g[100010];
double cnt = 0;

void dfs(int id, double price){
	cnt += ta[id]*price;
	for(int i=0; i<g[id].size(); i++) dfs(g[id][i], price*(1+0.01*r));
}

int main(){
 //freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,k;
	memset(ta,0,sizeof(ta));
	scanf("%d%lf%lf",&n, &p, &r);
	for(i=0; i<n; i++){
		scanf("%d",&j);
		if(j==0) scanf("%d",&ta[i]);
		while(j--){
			scanf("%d",&k);
			g[i].push_back(k);
		}
	}
	dfs(0, p);
	printf("%.1lf\n",cnt);
	return 0;
}
