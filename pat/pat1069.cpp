#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
int a[5];
int get(int x, int tag){ // tag=1 ， 减数 升序
    for(int i=3; i>=0; i--) a[i] = x%10, x/=10;
    if(tag) sort(a, a+4); else sort(a, a+4, greater<int>());
    int ans = 0;
    for(int i=0; i<=3; i++) ans = ans*10 + a[i];
    return ans;
}

int main(){
//    freopen("E:\\DataStruct\\PAT\\test.txt", "r", stdin);
    int x,y,n;
    scanf("%d",&n);
    do
    {
        x = get(n,0); y = get(n,1);
        n = x-y;
        printf("%04d - %04d = %04d\n", x, y, n);
    }while(n!=6174 && n);
    return 0;
}
