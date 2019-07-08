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

bool check(char *p){
	if(p[0]>='0' && p[0]<='9') return 1;
	else return 0;
}


char s0[13][5] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
char s1[13][5] = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int n,m;
	char num[10];
	scanf("%d",&n);
	getchar();
	while(n--){
		gets(num);
		if(check(num)){
			sscanf(num, "%d", &m);
			if(!m) {  printf("%s\n", s0[0]); continue;} 
			printf("%s", s1[m/13]);
			if(m/13 && m%13) printf(" ");
			if(m%13) printf("%s", s0[m%13]);
			printf("\n");
		}
		else{
			m = 0;
			if(strlen(num)>4){	
				for(int i=1; i<=12; i++)
					if(num[0]==s1[i][0] && num[1]==s1[i][1] && num[2]==s1[i][2]){
						m += i*13;
						break;
					}
				for(int i=0; i<=12; i++){
					if(num[4]==s0[i][0] && num[5]==s0[i][1] && num[6]==s0[i][2]){
						m += i;
						break;
					}		
				}
			}
			else{
				for(int i=1; i<=12; i++)
					if(num[0]==s1[i][0] && num[1]==s1[i][1] && num[2]==s1[i][2]){
						m = i*13;
						break;
					}
				if(m==0){
					for(int i=0; i<=12; i++)
						if(num[0]==s0[i][0] && num[1]==s0[i][1] && num[2]==s0[i][2]){
							m = i;
							break;
						}
					} 
			}
			printf("%d\n",m);
		}
	}
	return 0;
}
