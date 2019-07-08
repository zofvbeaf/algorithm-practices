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
const int maxn = 20;
int n;
int root;
int f[maxn],t[maxn][2];

void dfs(int x){
	if(x==-1) return;
	dfs(t[x][1]);
	n--;
	printf("%d%s", x, n ? " " : "\n");
	dfs(t[x][0]);
}

int main(){
	char x[2],y[2];	
	scanf("%d",&n);
	for(int i=0; i<10; i++){
		f[i] = -1;
		t[i][0] = t[i][1] = -1;
	} 
	for(int i=0; i<n; i++){
		scanf("%s%s",x,y);
		if(x[0]!='-') f[x[0]-'0'] = i, t[i][0] = x[0] - '0';
		else t[i][0] = -1;
		if(y[0]!='-') f[y[0]-'0'] = i, t[i][1] = y[0] - '0';
		else t[i][1] = -1;
	}

	for(root=0; root<n; root++) if(f[root]==-1) break;
	queue<int> q;
	q.push(root);
	
	while(!q.empty()){
		int p = q.front(); q.pop();
		printf("%s%d", p==root ? "" : " ", p);
		if(t[p][1]>=0) q.push(t[p][1]);
		if(t[p][0]>=0) q.push(t[p][0]);
	}
	printf("\n");
	dfs(root);
	return 0;
}
