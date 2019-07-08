#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<stack>
#include<vector>
#include<queue>
#include<math.h>
#include<functional>
using namespace std;

string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string pos[9] = {"","Shi", "Bai", "Qian", "Wan","Shi", "Bai", "Qian", "Yi"};
stack<string> ans;

int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	int n,i,j,x;
	scanf("%d",&x);
	n = abs(x);
	if(n==0) { printf("ling\n"); return 0; }
	for(i=0; n; i++,n/=10)
		if(n%10) { if(i) ans.push(pos[i]);  ans.push(num[n%10]); }
		else {
			if(i==4 && n%10000){ ans.push(pos[i]); continue; } 
			if(ans.empty() || ans.top()==num[0] | ans.top()==pos[4]) continue;
			ans.push(num[0]);
		}
	if(x<0) ans.push("Fu");
	while(!ans.empty()) {
		cout<<ans.top(); 
		ans.pop();
		if(!ans.empty()) cout<<" ";
	}
	return 0;
}
