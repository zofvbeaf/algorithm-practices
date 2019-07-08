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

int a[300],b[300];
char s1[1010],s2[1010];
int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,cnt=0,flag=1;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%s%s",s1,s2);
	for(i=0; s1[i]; i++) a[s1[i]-'0']++;
	for(i=0; s2[i]; i++) b[s2[i]-'0']++;
	for(i=0; i<300; i++) {
		if(a[i] < b[i]) cnt += b[i]-a[i],flag=0;
	}
	printf("%s %d\n",flag ? "Yes" : "No", flag ? strlen(s1)-strlen(s2) : cnt);
	return 0;
}
