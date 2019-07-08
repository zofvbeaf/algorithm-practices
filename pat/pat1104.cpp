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
const int maxn = 1e5 + 50;
int n;
int cnt[maxn];
vector<int> adj[maxn];
double p,r;

void dfs(int x, int l){
	cnt[x] = l;
	for(int i=0; i<adj[x].size(); i++)	dfs(adj[x][i], l+1);
}

int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int mmin = INF;
	int ans = 0;
	scanf("%d%lf%lf",&n,&p,&r);
	double res = p;
	for(int i=0,j,x; i<n; i++){
		scanf("%d",&j);
		while(j--){
			scanf("%d",&x);
			adj[i].push_back(x);
		}
	}
	dfs(0,1);
	for(int i=0; i<n; i++) if(mmin>cnt[i] && adj[i].empty()) mmin=cnt[i];
	for(int i=0; i<n; i++) if(cnt[i]==mmin && adj[i].empty()) ans++;
	mmin--;
	while(mmin--)	res *= 1 + 0.01*r;
	printf("%.4lf %d\n", res, ans);
	return 0;
}
