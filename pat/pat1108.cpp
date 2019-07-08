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
char s[1000];

bool check(char *p){
	int len = strlen(p);
	int flag = 0;
	double m;
	char *x = strchr(p,'.');
	if(x && strlen(x)>3) return 0;
	if(len==1 && (p[0]<'0' || p[0]>'9')) return 0;
	if(len>1 && p[0]!='-' && (p[0]<'0' || p[0]>'9')) return 0;
	for(int i=1; i<len; i++){
		if(p[i]=='.') {
			if(flag==0) { flag = 1;  continue;}
			else return 0;
		}
		if(p[i]<'0' || p[i]>'9') return 0;
	}
	sscanf(p,"%lf",&m);
	if(abs(m)>1000) return 0;
	return 1;
}

int main(){
	int cnt=0;
	double x,ans=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%s",s);
		if(check(s)) cnt++, sscanf(s,"%lf",&x), ans += x;
		else printf("ERROR: %s is not a legal number\n", s);
	}
	if(cnt) printf("The average of %d number%s is %.2lf\n", cnt, cnt==1 ? "" : "s", ans/cnt);
	else printf("The average of 0 numbers is Undefined\n");
	return 0;
}
