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
int n;
char s[100];
LL no[110],den[110];

LL gcd(LL a, LL b){
	if(a<0) a = -a;
	return b==0 ? a : gcd(b, a%b);
}

int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j;
	LL temp;
	LL intp = 0;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%s",s);
		sscanf(s, "%lld/%lld", &no[i], &den[i]);
	}
	for(i=1; i<n; i++){
		no[i] = no[i]*den[i-1] + no[i-1]*den[i];
		den[i] *= den[i-1];
		temp = gcd(no[i], den[i]);
		no[i] /= temp;
		den[i] /= temp;
		intp += no[i] / den[i];
		no[i] %= den[i];
	}
	if(n==1) intp += no[0] / den[0], no[0] %= den[0];
	if(intp!=0){
		printf("%lld",intp);
		if(no[i-1]!=0) printf(" %lld/%lld\n",no[i-1],den[i-1]);
		else printf("\n");
	} 
	else if(no[i-1]!=0) printf("%lld/%lld\n",no[i-1],den[i-1]);
	else printf("%lld\n",intp);
	
	return 0;
}
