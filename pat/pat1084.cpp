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

char a[100],b[100];
vector<char> ans;
int tag[300], flag[300];

void print(char x){
	if(x>='a' &&  x<='z') printf("%c",(x-32)), tag[(int)(x-'0'-32)] = 1, tag[(int)(x-'0')]=1;
	else if(x>='A' &&  x<='Z') printf("%c",x), tag[(int)(x-'0'+32)] =1, tag[(int)(x-'0')]=1;
	else printf("%c",x), tag[x-'0'] = 1;
}

int main(){
	//freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int  i, j, lena, lenb;
	memset(tag, 0, sizeof(tag));
	memset(flag, 0, sizeof(flag));
	scanf("%s%s", a, b);
	lena = strlen(a);
	lenb = strlen(b);
	for(i=0; i<lenb; i++) {
		if(b[i]>='a' &&  b[i]<='z')  flag[(int)(b[i]-'0'-32)] = 1, flag[(int)(b[i]-'0')]=1;
		if(b[i]>='A' &&  b[i]<='Z')  flag[(int)(b[i]-'0'+32)] =1, flag[(int)(b[i]-'0')]=1;
		else flag[b[i]-'0'] = 1;
	}
	for(i=0; i<lena; i++){
		if(flag[(int)(a[i]-'0')]) continue;
		else if(tag[(int)(a[i]-'0')]==0) print(a[i]);
	}
	printf("\n");
	return 0;
}
