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
int n,m,k,q;
int ans[1005],c[1005];
queue<int> p[22];

int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	
	for(int i=1; i<=k; i++) {
		scanf("%d",&c[i]);
		int now = 0;
		
		if(i<=n*m){ for(int j=1; j<n; j++) if(p[now].size() > p[j].size()) now = j; } 
		else for(int j=1; j<n; j++) if(p[now].front() > p[j].front()) now = j;
		
		if(p[now].empty()) ans[i] = 8*60 + c[i];
		else ans[i] = p[now].back() + c[i];
		
		p[now].push(ans[i]);
		if(p[now].size() > m) p[now].pop();
	}
	
	while(q--){
		int x;
		scanf("%d",&x);
		if(ans[x]-c[x] >= 17*60) printf("Sorry\n");
		else printf("%02d:%02d\n",ans[x]/60, ans[x]%60);
	}
	return 0;
}
