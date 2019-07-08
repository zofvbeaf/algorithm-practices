#include<cstdio>
#include<string.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long n,i,j,flag=0;
    scanf("%lld",&n);
    printf("%lld=",n);
    for(i=2; i*i <= n; i++){
        for(j=0; n%i==0; n/=i) j++;
        if(j) {
            if(flag) printf("*"); else flag=1; //第一个值前不输出*号，从后面开始都输出
            if(j>1) printf("%lld^%lld",i,j);
            else printf("%lld",i);
        }
    }

    if(flag){
        if(n>1) printf("*%lld\n",n); //输出最末位的素数因子
    }
    else printf("%lld\n",n); //表示原本的input的n值就为一个素数
	return 0;
}
