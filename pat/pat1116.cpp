#include<cstdio>
#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
using namespace std;

int n,k;
int ans[10015],v[10015];
string s[6] = {"","Mystery Award", "Minion", "Chocolate", "Are you kidding?", "Checked"};

bool isp(int x){
	if(x==2 || x==3) return 1;
	for(int i=2; i*i<=x; i++) if(x%i == 0) {
		return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for(int i=1,x; i<=n; i++){
		scanf("%d",&x);
		if(i==1) ans[x] = 1;
		else if(isp(i))	ans[x] = 2;
		else ans[x] = 3;
	}
	scanf("%d",&k);
	for(int i=1,x; i<=k; i++){
		scanf("%d",&x);
		printf("%04d: ",x);
		if(v[x]) cout<<s[5]<<endl;
		if(ans[x] && !v[x]) cout<<s[ans[x]]<<endl, v[x] = 1;
		else if(!v[x]) cout<<s[4]<<endl;
	}
	return 0;
}
