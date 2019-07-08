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

char s[100010];
LL p[100010],t[100010];
int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	LL ans = 0;
	scanf("%s",s);
	p[0] = s[0]=='P';
	t[strlen(s)] = 0;
	for(int i=1; s[i]; i++) p[i] = p[i-1] + (s[i]=='P');
	for(int i=strlen(s)-1; s[i]; i--) t[i] = t[i+1] + (s[i]=='T');
	for(int i=1; s[i]; i++){
		if(s[i]=='A'){
			ans = (ans + (p[i]*t[i])%1000000007)%1000000007;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
