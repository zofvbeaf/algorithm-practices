#include<cstdio>
#include<string.h> //memset
using namespace std;

int main(){
    int k,m;
    double a[1002],b[1002],c[2002];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        scanf("%d",&m);
        scanf("%lf",a+m);    //double的输入
    }
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        scanf("%d",&m);
        scanf("%lf",b+m);
    }
    k=0;
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            c[i+j] += a[i]*b[j];
        }

    }
    for(int i=2001; i>=0; i--){
        if(c[i]) k++;
    }
    printf("%d",k);
    for(int i=2001; i>=0; i--){
        if(c[i]!=0){
            printf(" %d %.1f",i,c[i]); //小数输出，小数点后1位
        }
    }
    printf("\n");  //最后输出的一行有换行
    return 0;
}
