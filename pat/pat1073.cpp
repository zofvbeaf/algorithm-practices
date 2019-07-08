#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<cstring>
#include<vector>
#include<math.h>
#include<functional>
using namespace std;

int main(){
// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int nume,i,j;
	char s[30000];
	char ibefore[30000];
	char fbefore[30000];
	char *p;
	scanf("%s",s);
	p = s;
	if(p[0]=='-') printf("-");
	if(p[0]=='-' || p[0]=='+') p++;
	strncpy(ibefore, p, strlen(p)-strlen(strchr(s, '.')));
	p = strchr(s, '.') + 1;
	strncpy(fbefore, p, strlen(p)-strlen(strchr(s, 'E')));
	sscanf(strchr(s, 'E')+1, "%d", &nume);
	j = strlen(ibefore) + nume;
	strcat(ibefore,fbefore);
	if(j<0) printf("0.");
	if(j==0) printf("0");
	else for(i = j; i<0; i++) printf("0");
	for(i=0; i<strlen(ibefore); i++){
		if(i == j) printf(".");
		printf("%c",ibefore[i]);
	} 
	for(i = strlen(ibefore); i<j; i++) printf("0");
	printf("\n");
	return 0;
}
