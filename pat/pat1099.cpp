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
const int maxn = 150;
int n,tot=0;
int t[maxn][2],v[maxn],a[maxn];

void dfs(int x){
	if(x==-1) return;
	dfs(t[x][0]);
	v[x] = a[tot++];
	dfs(t[x][1]);
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d%d",&t[i][0],&t[i][1]);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n);
	dfs(0);
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		n = q.front(); q.pop();
		printf("%s%d", n ? " " : "", v[n]);
		if(t[n][0]!=-1) q.push(t[n][0]);
		if(t[n][1]!=-1) q.push(t[n][1]);
		
	}
	return 0;
}
