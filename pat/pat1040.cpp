#include<cstdio>
#include<string.h>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int mx=0,id=0,i,ans=0,len;
    char s[1002];
    gets(s);
    len = strlen(s);
    char ss[2*len+10];
    int p[2*len+10];
    ss[0] = 2;
    p[0] = 0;
    for(i=0; s[i]; i++){
        ss[2*i+1] = ss[2*i+3] = 1;
        ss[2*i+2] = s[i];
        p[2*i+1] = p[2*i+2] = 0;
        p[2*i+3] = 0;
    }
    for(i=1; ss[i]; i++){
        p[i] = mx > i ? min(p[2*id-i],mx-i) : 1;
        while(ss[i+p[i]] == ss[i-p[i]]) p[i]++;
        mx = i+p[i] > mx ? i+p[id=i] : mx;
        ans = max(ans,p[i]-1);
    }
    printf("%d\n",ans);
	return 0;
}
