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
const int INF = 1<<30;
char s[1110][1300];
int n, cnt=0,len[1110];
bool check(int pos){
	int i;
	for(i=1; i<n; i++) if(s[i][len[i]-pos] != s[0][len[0]-pos]) return 0;
	return 1;
}

int main(){
// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int i,j,mmin = INF;
	string ans="";
	scanf("%d",&n);
	getchar();
	for(i=0; i<n; i++) gets(s[i]), len[i] = strlen(s[i]), mmin = mmin < len[i] ? mmin : len[i];
	for(i=1; i<=mmin; i++) if(check(i)) ans = s[0][len[0]-i] + ans; else break;
	if(ans=="") ans = "nai";
	cout<<ans<<endl;
	
	return 0;
}
