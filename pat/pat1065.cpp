#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const ULL INF = ((ULL)1<<63);
char s[100];
int f1,f2,f3;
ULL a,b,c;

bool check(){

    scanf("%s",s); f1 = s[0]=='-'; sscanf(f1 ? s+1 : s, "%llu", &a);
    scanf("%s",s); f2 = s[0]=='-'; sscanf(f2 ? s+1 : s, "%llu", &b);
    scanf("%s",s); f3 = s[0]=='-'; sscanf(f3 ? s+1 : s, "%llu", &c);

    if(a==INF && b==a && f1==f2) return !f1;
    if(f1==f2) b += a;
    else if(a > b) { f2 = f1; b = a - b; } else b -= a;
    return f2 == f3 ? (f2 ? b < c : b > c) : f3;
}

int main(){
	int t;
	scanf("%d",&t);
    for(int i=1; i<=t; i++){
        printf("Case #%d: %s\n",i,check() ? "true" : "false");
    }

	return 0;
}
