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
const int maxn = 1e4 + 50;

int n,k,tot,ans,p[105];
int c[maxn],s[maxn],a[maxn];
bool comp(const int &x, const int &y){
	return c[x] < c[y];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0,x,y,z,w; i<n; i++){
		scanf("%d:%d:%d%d",&x,&y,&z,&w);
		x = x*3600 + y*60 + z;		//不能在读取的时候算ans，因为不一定8：00之前来就能服务到
		if(w>60) w = 60;
		s[i] = w * 60;
		a[i] = i;
		c[i] = x;
	}
	sort(a, a+n, comp);
	for(int i=0; i<k; i++) p[i] = 8*3600;
	for(int i=0; i<n; i++){
		if(c[a[i]] > 17*3600) break;
		int now = 0;
		for(int j=1; j<k; j++) if(p[now] > p[j]) now = j;
	//	if(c[a[i]] >= 17*3600 || p[now] > 17*3600) break; 这样写是错误的，因为在17：00之前到的都应享受到服务，即使17：00才轮到
		if(p[now] > c[a[i]]) ans += p[now] - c[a[i]], p[now] += s[a[i]];
		else p[now] =  c[a[i]] + s[a[i]];
		tot++;
	}
	if(tot) printf("%.1lf\n",(ans*1.0/tot)/60.0);
	else printf("0.0\n");
	return 0;
}
