#[UVALive3027 Corporative Network](https://vjudge.net/problem/UVALive-3027)
#SOLUTION
+ 并查集
#AC CODE
```c++
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 20010;
int d[maxn];

int findset(int *p, int x) { //带路径压缩
    if(p[x] < 0) return x;
    int root = findset(p, p[x]);
    d[x] += d[p[x]];
    return p[x] = root;
}

int main()
{
    int f[maxn];
    int T, n, x, y;
    char c[5];
    scanf("%d", &T);
    while(T--){
        memset(f, -1, sizeof(f));
        memset(d, 0, sizeof(d));
        scanf("%d", &n);
        while(scanf("%s", c) == 1 && c[0] != 'O'){
            if(c[0] == 'I'){
                scanf("%d%d", &x, &y);
                if(!n) continue;
                n--;
                f[x] = y;
                d[x] = abs(x-y) % 1000;
            }
            else {
                scanf("%d", &x);
                findset(f, x);
                printf("%d\n", d[x]);
            }
        }
    }
    return 0;
}

```
