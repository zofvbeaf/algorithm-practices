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

int n,a[200],b[200];

int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j;
	int s=0, e=0;
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%d",&a[i]);
	for(i=0; i<n; i++) scanf("%d",&b[i]);
	for(s=1; s<n; s++) if(b[s] < b[s-1]) break; //0 ~ s-1 是升序
	for(e=s; e<n; e++) if(a[e]!=b[e]) break; 
	if(e==n) {
		printf("Insertion Sort\n");
		sort(a, a+s+1);
	}
	else{
		printf("Merge Sort\n"); //之后对原始序列进行归并操纵，并逐次比较是否和给出的序列相同
		for(int flag=1, k=1; flag&& k<=n; k <<= 1){
			for(i=flag=0; i<n; i++) if(a[i]!=b[i]) { flag = 1; break; }
			for(i=0; i<n; i += k) sort(a+i, a+min(i+k,n));
		}			
	}
	for(i=0; i<n; i++) printf("%d%s",a[i],i==n-1 ? "\n": " ");
	return 0;
}
