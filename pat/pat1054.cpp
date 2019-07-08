#include<cstdio>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;
int pix[16777300];
int main()
{
    int m,n,mmax = -1,id,i,j,x;
    scanf("%d%d",&m,&n);
    for(i=0; i<n*m; i++){
        scanf("%d",&x);
        pix[x]++;
        if(mmax < pix[x]) mmax = pix[id=x];
    }
    printf("%d\n",id);
	return 0;
}
