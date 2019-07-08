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
typedef unsigned long long uLL;
const int INF = 1<<30;
const int maxn = 1e5 + 50;

int toint(char c){
	int ans;
	if(c > '9') ans = c-'a'+10;
	else ans = c-'0';
	return ans;
}

uLL change(string s, uLL r){
	uLL ans = 0;
	for(int i=0; s[i]; i++)  ans = ans*r + toint(s[i]);
	return ans;
}

int findmax(string s){
	int ans=0;
	for(int i=0; s[i]; i++) if(ans < toint(s[i])) ans = toint(s[i]);
	return ans;
}

int main(){
	int tag,r;
	uLL x,y;
	string a,b;
	cin>>a>>b>>tag>>r;
	if(tag==2) swap(a,b);
	x = change(a,r);
	for(uLL l=findmax(b)+1, r = x+1; l <= r; ){
		uLL m = l+r >> 1;
		y = change(b,m);
		if(y==x) { printf("%lld\n",m); return 0; }
		else if(y>x) r = m-1;
		else l = m+1;
	}
	printf("Impossible\n");
	return 0;
}
