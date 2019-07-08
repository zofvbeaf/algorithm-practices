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
int a[maxn],mi[maxn],ma[maxn];
vector<int> res;
int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	if(n==1){ printf("1\n%d\n",a[0]); return 0; }
	ma[0] = a[0]; mi[n-1] = a[n-1];
	for(int i=1; i<n; i++) ma[i] = max(ma[i-1], a[i]);
	for(int i=n-2; i>=0; i--) mi[i] = min(mi[i+1],a[i]);
	if(a[0]<mi[1]) res.push_back(a[0]);
	for(int i=1; i<n-1; i++) if(a[i]<mi[i+1] && a[i]>ma[i-1]) res.push_back(a[i]);
	if(n>=2 && a[n-1]>ma[n-2]) res.push_back(a[n-1]);
	printf("%d\n",res.size());
	for(int i=0; i<res.size(); i++) printf("%s%d", i ? " " : "", res[i]);
	printf("\n");
	return 0;
}
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
int a[maxn],mi[maxn],ma[maxn];
vector<int> res;
int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	if(n==1){ printf("1\n%d\n",a[0]); return 0; }
	ma[0] = a[0]; mi[n-1] = a[n-1];
	for(int i=1; i<n; i++) ma[i] = max(ma[i-1], a[i]);
	for(int i=n-2; i>=0; i--) mi[i] = min(mi[i+1],a[i]);
	if(a[0]<mi[1]) res.push_back(a[0]);
	for(int i=1; i<n-1; i++) if(a[i]<mi[i+1] && a[i]>ma[i-1]) res.push_back(a[i]);
	if(n>=2 && a[n-1]>ma[n-2]) res.push_back(a[n-1]);
	printf("%d\n",res.size());
	for(int i=0; i<res.size(); i++) printf("%s%d", i ? " " : "", res[i]);
	printf("\n");
	return 0;
}
