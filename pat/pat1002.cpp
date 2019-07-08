#include <cstdio>
#include<string.h>
using namespace std;

int main(){
    int k,m;
    double a[1002],b[1002];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        scanf("%d",&m);
        scanf("%lf",a+m);
    }
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        scanf("%d",&m);
        scanf("%lf",b+m);
    }
    k=0;
    for(int i=0; i<1002; i++){
        a[i] += b[i];
        if(a[i]!=0){
            k++;
        }
    }
    printf("%d",k);
    for(int i=1001; i>=0; i--){
        if(a[i]!=0){
            printf(" %d %.1f",i,a[i]);
        }
    }
    printf("\n");
    return 0;
}
