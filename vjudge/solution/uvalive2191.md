#[UVALive2191 Potentiometers](https://vjudge.net/problem/UVALive-2191)
#SOLUTION
+ 树状数组/BIT/Fenwick树 
+ O(nlogn)
#AC CODE
```c++
#include <cstdio>
#include <string.h>

using namespace std;

const int maxn = 200010;

int c[maxn], f[maxn], n;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int d) {
    while(x <= n) 
        c[x] += d, x += lowbit(x);
}

int sum(int x) {
    int ret = 0;
    while(x > 0) 
        ret += c[x], x -= lowbit(x);
    return ret;
}

int main()
{
    int x, y, cnt = 0;
    char cmd[10];
    f[0] = 0;
    while(~scanf("%d", &n) && n) {

        if(cnt++) printf("\n");
        printf("Case %d:\n", cnt);

        memset(c, 0, sizeof(c));

        for(int i = 1; i <= n; i++) scanf("%d", &f[i]), add(i, f[i]);

        while(~scanf("%s", cmd) && cmd[0] != 'E') {
            scanf("%d%d", &x, &y);
            if(cmd[0] == 'S'){
                add(x, y-f[x]);
                f[x] = y;
            }
            else printf("%d\n", sum(y) - sum(x-1));
        }
    }
    return 0;
}
```
