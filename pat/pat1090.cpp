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
int n,dist[100010],mmax = 0;
double p,r;
vector<int> g[100010];

void dfs(int x, int l){
	dist[x] = l;
	mmax = mmax > dist[x] ? mmax : dist[x];
	for(int i=0; i<g[x].size(); i++) dfs(g[x][i],l+1);
}

int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,root;
	int cnt=0;
	scanf("%d%lf%lf",&n,&p,&r);
	r = r/100 + 1;
	for(i=0; i<n; i++){
		dist[i] = 0;
		scanf("%d",&j);
		if(j==-1) root = i;
		else g[j].push_back(i);
	}
	dfs(root,1);
	for(i=0; i<n; i++) if(dist[i]==mmax) cnt++;
	p *= pow(r, mmax-1);
	printf("%.2lf %d\n", p, cnt);
	return 0;
}
