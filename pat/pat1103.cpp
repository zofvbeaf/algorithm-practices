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
const int maxn = 450;
int c[maxn];
int N,K,P,mmax;
vector<int> res;
vector<int> ans;
void dfs(int s, int k, int n, int sum){
	if(k==0){
		if(n==0 && mmax <= sum) ans = res, mmax = sum;
	}
	else{
		for(int i=s; n>0 && i<21; i++){
			if(n-c[i]<0) break;
			res.push_back(i);
			dfs(i,k-1,n-c[i],sum+i);
			res.pop_back();
		}
	}
}

int main(){
	scanf("%d%d%d",&N,&K,&P);
	for(int i=1; i<21; i++){
		c[i] = 1;
		for(int j=0; j<P; j++) c[i] *= i;
	}
	dfs(1,K,N,0);
	if(ans.empty()) printf("Impossible\n");
	else{
		printf("%d = ",N);
		for(int i=K-1; i>=0; i--)
			printf("%d^%d%s", ans[i], P, i ? " + " : "\n");
	}
	return 0;
}
