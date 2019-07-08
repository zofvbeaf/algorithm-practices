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
const int maxn = 1e3 + 50;

int k,v[300];
char s[maxn];
int main(){
	scanf("%d%s",&k,s);
	for(int i=0,j=0; s[i]; i=j){
		while(s[j] && s[i]==s[j]) j++;
		if((j-i)%k) v[s[i]] = -1;
		else if(!v[s[i]])	v[s[i]] = 1;
	}
	
	for(int i=0; s[i]; i++){
		if(v[s[i]]==1) printf("%c", s[i]), v[s[i]]=2;
	} 
	printf("\n");
	
	for(int i=0; s[i]; ){
		printf("%c",s[i]);
		if(v[s[i]]==2) i += k;
		else  i++;
	}
	return 0;
}
