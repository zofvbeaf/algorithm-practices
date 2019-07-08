#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
string s[2000000];
char a,b;
int tot=0;
bool check(char x){
	return x>='a'&& x<='z' || x>='0'&& x<='9' || x>='A'&& x<='Z';
}

int main(){
	b = '\n';
	while((a = getchar()) != '\n'){
		if(check(a)) {
			if(a>='A'&&a<='Z')
				a += 32;
			s[tot] += a;
		}
		else if(check(b)) tot++;
		b = a;
	}
	if(s[tot]!="") tot++;
	sort(s, s+tot);
	int ans = 1, id = 0;
	for(int i=1,k=1; i<tot; i++){
		
		if(s[i]==s[i-1]) k++;
		if(i==tot-1 || s[i] != s[i-1]){
			if(ans < k) ans = k, id = i-1;
			k = 1;
		}
	}
	cout<<s[id]<<" "<<ans<<endl;
	return 0;
}
