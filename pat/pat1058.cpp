#include<cstdio>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;

int main()
{
    int a1,b1,c1,a2,b2,c2,carry=0;
    scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
    c2 += c1;
    if(c2>=29) carry=1, c2-=29;
    b2 += b1 + carry;
    carry=0;
    if(b2>=17) carry=1, b2-=17;
    a2 += a1 + carry;
    printf("%d.%d.%d\n",a2,b2,c2);
	return 0;
}
