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

int m,n;
int table[100000];
bool isPrime(int x){
	if(x<2) return 0;
	if(x<=3) return 1;
	for(int i=2; i*i<=x; i++) if(x%i==0) return 0;
	return 1;
}

int main(){
// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,k;
	memset(table, 0, sizeof(table));
	scanf("%d%d",&m,&n);
	while(1){ if(isPrime(m)) break; else m++; }
	while(n--){
		int flag = 1;
		scanf("%d",&j);	
		for(i=0; i < m; i++){
			if(!table[(j+i*i)%m]) {
				flag = 0;
				printf("%d",(j+i*i)%m);
				table[(j+i*i)%m]=1; 
				break;
			}
		}
		if(flag) printf("-");
		printf("%s", n ? " " : "\n");
	}
	return 0;
}
