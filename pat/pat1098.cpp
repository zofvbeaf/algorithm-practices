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
int a[150],b[150];
int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	for(int i=0; i<n; i++) scanf("%d",&b[i]);
	int s,e;
	for(s=0; s<n-1; s++) if(b[s]>b[s+1]) break;
	for(e=s+1; e<n; e++) if(b[e]!=a[e]) break;
	if(e==n){
		printf("Insertion Sort\n");
		sort(a,a+s+2);
		for(int i=0; i<n; i++) printf("%d%s", a[i], i==n-1 ? "\n" : " ");
	}
	else{
		printf("Heap Sort\n");
		for(e=1; e<n; e++) if(b[e]>b[0]) break;
		swap(b[0],b[e-1]);
		for(int i=0; 2*i+1<e-1; ){
			if(2*i+2<e-1){
				if(b[2*i+1]>b[2*i+2]){
					if(b[2*i+1]>b[i]) swap(b[2*i+1],b[i]), i = 2*i+1;
				}
				else if(b[2*i+2]>b[i]) swap(b[2*i+2],b[i]), i = 2*i+2;
				else  break; 			
			} 
			else if(b[2*i+1]>b[i]) swap(b[2*i+1],b[i]), i = 2*i+1;
			else break; 
			
		}
		for(int i=0; i<n; i++) printf("%d%s", b[i], i==n-1 ? "\n" : " ");
	}
	return 0;
}
