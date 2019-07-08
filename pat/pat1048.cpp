#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;



int main(){
    int i,j,n,m;
    int sum[1002];
    memset(sum,0,sizeof(sum));
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++){
        scanf("%d",&j);
        sum[j]++;
    }
    for(i=1; i+i<=m; i++){
        if(i+i==m ){
            if(sum[i]>=2){
                printf("%d %d\n",i,i);
                return 0;
            }
        }
        else if(sum[i] && sum[m-i]) {
            printf("%d %d\n",i,m-i);
            return 0;
        }
    }

    printf("No Solution\n");
	return 0;
}
