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
char s[200];

LL gcd(LL a, LL b){
	return b==0 ? a : gcd(b, a%b);
}

void get(LL &x, LL &y){
	if(!x) { y=1; return; }
	LL g = gcd(x,y);
	x = x/g;  y = y/g;
}

void write(LL x, LL y, LL z){
	if(x && y) printf("(-"); //x为'-' 且y 不为0
	if(y/z) printf("%lld",y/z);
	if(y/z && y%z) printf(" ");
	if(y%z)	printf("%lld/%lld",y%z,z);
	if(!(y/z) && !(y%z))  printf("0");
	if(x && y) printf(")");
}

void add(LL a, LL b, LL c, LL x, LL y, LL z){
	LL g = gcd(c,z);
	LL gg = c/g * z;
	b = z/g * b;
	y = c/g * y;
	if(a == x) b += y;
	else{
		if(b > y) b -= y; else a = x, b = y-b;
	}
	g = gcd(b,gg);
	b /= g; c = gg/g;
	write(a,b,c);
}

int main(){
	// freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
	LL a,b,c,x,y,z;
	scanf("%s",s);
	a = s[0]=='-';
	sscanf(s+a, "%lld/%lld", &b, &c);
	get(b,c);
	
	scanf("%s",s);
	x = s[0]=='-';
	sscanf(s+x, "%lld/%lld", &y, &z);
	get(y,z);
	
	write(a,b,c); printf(" + "); write(x,y,z); printf(" = ");
	add(a,b,c,x,y,z); printf("\n");
	
	write(a,b,c); printf(" - "); write(x,y,z); printf(" = ");
	add(a,b,c,x^1,y,z); printf("\n");
	
	write(a,b,c); printf(" * "); write(x,y,z); printf(" = ");
	LL g = gcd(b*y, c*z); write(a^x, b*y/g, c*z/g); printf("\n");
	
	write(a,b,c); printf(" / "); write(x,y,z); printf(" = ");
	if(y==0) { printf("Inf\n"); return 0; }
	g = gcd(b*z, c*y); write(a^x, b*z/g, c*y/g); printf("\n");
	
	return 0;
}
