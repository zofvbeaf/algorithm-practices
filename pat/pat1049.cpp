#include<cstdio>
using namespace std;

int main()
{
    int n,i,ans=0;
    scanf("%d",&n);
    //从个位开始往高位，逐位相加其位上1的个数
    int pos = 1; //用于标记当前位是个十百千万位的某一个
    int tail = 0; //用于标记最末的某几位的值
    int head = n/10; //用于标记前几位的值
    while(n){
        ans += head * pos;
        if(n%10 > 1) ans += pos;
        else if(n%10 == 1) ans += tail + 1; //比如13，应为3+1,10的十位也为1
        tail += n%10 * pos;
        pos *= 10;
        head /= 10;
        n /= 10;
    }
    printf("%d\n",ans);
	return 0;
}
