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
typedef long long LL;
vector<int> num;
int n,p;

int main(){
	int i,j;
	int ans=0;
	scanf("%d%d",&n,&p);
	for(i=0; i<n; i++) scanf("%d",&j), num.push_back(j);
	sort(num.begin(), num.end());
	for(i=0,j=0; i<n; i++){
		while(j<n && (LL)num[i]*p >= (LL)num[j]) j++;
		ans = max(j-i, ans);
	} 
	printf("%d\n",ans);
	
	return 0;
}
