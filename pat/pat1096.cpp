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
int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	LL i,j,k,cnt,n;
	scanf("%lld",&n);
	for(i=11; i>1; i--){	
		for(j=2; ; j++){
			cnt = 1;
			for(k=j; k<j+i ; k++) cnt *= k;
			if(cnt > n) break;
			if(n%cnt==0){
				printf("%lld\n",i);
				for(k=j; k<j+i ; k++) printf("%lld%s", k, k==j+i-1 ? "\n" : "*");
				return 0;
			}
		}
	}
	for(j=2; j*j<=n ; j++) if(n%j==0){
		printf("1\n%lld\n",j);
		return 0;
	} 
	printf("1\n%lld\n",n);
	return 0;
}
