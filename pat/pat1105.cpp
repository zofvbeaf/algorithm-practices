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
int n;
int m,k;
int a[maxn],res[maxn][maxn];

int u[4] = {0,1,0,-1};
int v[4] = {1,0,-1,0};

int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(m=(int)sqrt((double)n); m*(m-i)<=n; m++) if(m*(m-i)==n) break;
		if(m*(m-i)==n) break;
	}
	k = n/m;
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	sort(a, a+n, greater<int>());
	for(int i=0,x=1,y=1,z=0; i<n; i++){
		res[x][y] = a[i];
		if(x+u[z]<1 || x+u[z]>m || y+v[z]<1 || y+v[z]>k) z = (z+1)%4;
		else if(res[x+u[z]][y+v[z]]) z = (z+1)%4;
		x += u[z]; y += v[z];
	}
	for(int i=1; i<=m; i++){
		for(int j=1; j<=k; j++)
			printf("%d%s", res[i][j], j==k ? "\n" : " ");
	}
	return 0;
}
