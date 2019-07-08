#[UVALive3644 X-Plosives](https://vjudge.net/problem/UVALive-3644)
#SOLUTION
+ 并查集
#AC CODE
```c++
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 100010;

int findset(int *p, int  x){ //带路径压缩
    return p[x] >= 0 ? p[x] = findset(p, p[x]) : x;
}

int main()
{
    int f[maxn];
    int x, y, ans;
    while(~scanf("%d", &x)){
        memset(f, -1, sizeof(f));
        ans = 0;
        while(x != -1){
            scanf("%d", &y);
            x = findset(f, x); y = findset(f, y);
            if(x == y) ans++;
            else f[x] = y;
            scanf("%d", &x);
        }
        printf("%d\n", ans);
    }
    return 0;
}
```
