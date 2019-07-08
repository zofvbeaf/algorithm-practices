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
int n,a[maxn],sum[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) sum[i] = sum[i-1] + a[i];
	printf("%d %d\n", n%2, sum[n]-2*sum[n/2]);
	return 0;
}
